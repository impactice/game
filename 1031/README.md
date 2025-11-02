# Git & GitHub 완벽 가이드

> 깃과 깃허브를 활용한 버전 관리, 협업, 그리고 웹 호스팅 가이드

## 📚 목차

- [01. 깃 시작하기](#01-깃-시작하기)
- [02. 깃으로 버전 관리하기](#02-깃으로-버전-관리하기)
- [03. 깃과 브랜치](#03-깃과-브랜치)
- [04. 깃허브 시작하기](#04-깃허브-시작하기)
- [05. 깃허브로 협업하기](#05-깃허브로-협업하기)
- [06. 깃허브에서 소통하기](#06-깃허브에서-소통하기)
- [07. VS Code로 깃 다루기](#07-vs-code로-깃-다루기)
- [08. 깃허브 페이지 만들기](#08-깃허브-페이지-만들기)
- [NEW. 깃허브 최신 기능](#new-깃허브-최신-기능)

---

## 01. 깃 시작하기

### 깃이란?

**깃(Git)** - 지옥에서 온 문서 관리자

깃으로 할 수 있는 3가지:

1. **버전 관리**: 문서 수정 시 언제, 무엇을 변경했는지 기록
2. **백업**: 깃허브 같은 원격 저장소에 파일 복제
3. **협업**: 여러 사람이 함께 작업하며 변경 내역 추적

### 깃 설치하기

#### 윈도우
1. https://git-scm.com/ 접속
2. Download for Windows 클릭
3. 설치 시 주요 설정:
   - 기본 편집기: Vim
   - 기본 브랜치명: **main** (권장)
   - 줄바꿈 처리: Checkout Windows-style, commit Unix-style

#### 맥
````bash
# Homebrew 설치
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Git 설치
brew install git
````

### 깃 환경 설정
````bash
# 사용자 정보 등록
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"

# 설정 확인
git config --list
````

### 기본 리눅스 명령어

| 명령어 | 설명 | 예시 |
|--------|------|------|
| `pwd` | 현재 디렉터리 경로 확인 | `pwd` |
| `ls` | 파일/디렉터리 목록 | `ls -la` |
| `cd` | 디렉터리 이동 | `cd Documents` |
| `mkdir` | 디렉터리 생성 | `mkdir project` |
| `rm` | 파일/디렉터리 삭제 | `rm -r test/` |
| `clear` | 화면 지우기 | `clear` |
| `cat` | 파일 내용 확인 | `cat file.txt` |

### Vim 편집기 기본 사용법
````bash
# 파일 열기/생성
vim filename.txt
````

**모드 전환**
- `i` 또는 `a`: 입력 모드로 전환
- `Esc`: ex 모드로 전환

**ex 모드 명령**
- `:w` - 저장
- `:q` - 종료
- `:wq` - 저장 후 종료
- `:q!` - 저장하지 않고 강제 종료

---

## 02. 깃으로 버전 관리하기

### 깃 저장소 만들기
````bash
# 디렉터리 생성 및 이동
mkdir hello-git
cd hello-git

# 깃 저장소 초기화
git init

# 또는 한 번에 처리
git init hello-git
cd hello-git
````

### 버전 관리의 3단계
````
작업 트리(Working Tree) → 스테이지(Stage) → 저장소(Repository)
     수정/생성          git add        git commit
````

1. **작업 트리**: 파일을 수정하고 저장하는 디렉터리
2. **스테이지**: 버전으로 만들 파일이 대기하는 곳
3. **저장소**: 스테이지의 파일들을 버전으로 저장하는 곳

### 기본 깃 명령어

#### 파일 상태 확인
````bash
git status
````

#### 스테이징
````bash
# 특정 파일 스테이징
git add filename.txt

# 모든 파일 스테이징
git add .
````

#### 커밋
````bash
# 스테이징 후 커밋
git commit -m "커밋 메시지"

# 스테이징과 커밋 동시 수행 (tracked 파일만)
git commit -am "커밋 메시지"
````

#### 커밋 로그 확인
````bash
# 전체 로그
git log

# 한 줄로 보기
git log --oneline

# 그래프로 보기
git log --oneline --graph --all

# 파일 변경 내역 포함
git log --stat
````

#### 변경 사항 확인
````bash
# 작업 트리와 최신 커밋 비교
git diff

# 특정 커밋 간 비교
git diff commit1 commit2
````

### 파일 상태

| 상태 | 설명 |
|------|------|
| **Untracked** | 한 번도 커밋하지 않은 파일 |
| **Tracked** | 한 번이라도 커밋한 파일 |
| **Unmodified** | 수정하지 않은 상태 |
| **Modified** | 수정했지만 스테이징 안 한 상태 |
| **Staged** | 스테이징된 상태 (커밋 대기) |

### 작업 되돌리기

#### 작업 트리 수정 취소
````bash
git restore filename.txt
````

#### 스테이징 취소
````bash
# 전체 스테이징 취소
git restore --staged .

# 특정 파일만
git restore --staged filename.txt
````

#### 최신 커밋 취소
````bash
# 커밋과 스테이징 모두 취소 (파일은 작업 트리에 유지)
git reset HEAD^

# 특정 커밋으로 되돌리기
git reset --hard <commit-hash>
````

#### 커밋 취소 (이력 유지)
````bash
# 커밋을 취소하되 이력은 남김
git revert <commit-hash>
````

---

## 03. 깃과 브랜치

### 브랜치란?

**브랜치(Branch)** - 독립적인 작업 공간을 만들어 동시에 여러 작업을 진행할 수 있게 해주는 기능
````
main ─●─●─●─●
        └─● apple 브랜치
        └─● google 브랜치
        └─● ms 브랜치
````

### 브랜치 기본 명령어

#### 브랜치 확인 및 생성
````bash
# 브랜치 목록 확인
git branch

# 새 브랜치 생성
git branch <branch-name>

# 브랜치 생성과 동시에 전환
git switch -c <branch-name>
````

#### 브랜치 전환
````bash
# 브랜치 전환
git switch <branch-name>

# 이전 명령어 (호환성)
git checkout <branch-name>
````

#### 브랜치 삭제
````bash
git branch -d <branch-name>
````

### 브랜치 정보 확인
````bash
# 모든 브랜치의 커밋 확인
git log --branches

# 그래프로 브랜치 관계 확인
git log --oneline --graph --all

# 브랜치 간 차이 확인
git log main..feature
````

### 브랜치 병합

#### Fast-Forward 병합
````bash
# main 브랜치로 전환
git switch main

# feature 브랜치 병합
git merge feature
````

#### 3-Way 병합
````bash
# 서로 다른 파일 수정 시 자동 병합
git merge feature
````

#### 충돌 해결
````bash
# 충돌 발생 시 파일에 다음과 같이 표시됨:
<<<<<<< HEAD
현재 브랜치의 내용
=======
병합할 브랜치의 내용
>>>>>>> feature

# 충돌 해결 후
git add .
git commit -m "Merge conflict resolved"
````

### Cherry-pick
````bash
# 특정 커밋만 가져오기
git cherry-pick <commit-hash>
````

---

## 04. 깃허브 시작하기

### 깃허브란?

**GitHub** - 깃 기반 원격 저장소 호스팅 서비스

주요 기능:
- 원격 저장소 제공
- 코드 백업
- 협업 도구
- 포트폴리오
- 오픈소스 참여

### 깃허브 가입

1. https://github.com 접속
2. Sign up 클릭
3. 이메일, 비밀번호, 사용자명 입력
4. 이메일 인증

### 원격 저장소 만들기

1. 깃허브 로그인
2. `+` → `New repository` 클릭
3. 저장소 설정:
   - **Repository name**: 저장소 이름
   - **Description**: 설명 (선택)
   - **Public/Private**: 공개 여부
   - **Add a README**: README 파일 추가 여부

### 지역 저장소와 원격 저장소 연결

#### HTTPS 방식
````bash
# 원격 저장소 연결
git remote add origin https://github.com/username/repo-name.git

# 연결 확인
git remote -v

# 첫 푸시 (main 브랜치)
git push -u origin main

# 이후 푸시
git push
````

#### SSH 방식
````bash
# SSH 키 생성
ssh-keygen

# 퍼블릭 키 복사 (윈도우)
clip < ~/.ssh/id_rsa.pub

# 퍼블릭 키 복사 (맥)
cat ~/.ssh/id_rsa.pub | pbcopy

# 깃허브에서 Settings → SSH and GPG keys → New SSH key
# 복사한 키를 붙여넣기

# SSH 주소로 원격 저장소 연결
git remote add origin git@github.com:username/repo-name.git
````

### 푸시와 풀

#### 푸시 (Push)
````bash
# 원격 저장소로 커밋 올리기
git push origin main
````

#### 풀 (Pull)
````bash
# 원격 저장소의 변경사항 가져오기
git pull origin main
````

---

## 05. 깃허브로 협업하기

### 원격 저장소 복제
````bash
# HTTPS 방식
git clone https://github.com/username/repo-name.git

# 디렉터리명 지정
git clone https://github.com/username/repo-name.git my-project
````

### 협업 워크플로우
````
1. git pull (최신 상태 유지)
2. 작업 수행
3. git add & git commit
4. git pull (충돌 방지)
5. git push
````

### 원격 브랜치

#### 원격 브랜치 확인
````bash
git branch -r
git branch -a
````

#### 원격 브랜치 가져오기
````bash
# Fetch: 정보만 가져오기
git fetch origin

# Pull: 가져와서 병합까지
git pull origin branch-name
````

#### 원격 브랜치에 푸시
````bash
git push origin feature-branch
````

### 공동 작업자 추가

1. 저장소 → Settings
2. Collaborators
3. Add people
4. 이메일 입력 후 초대
5. 초대받은 사람은 Accept invitation

### Pull Request (PR)

#### PR 생성
1. 브랜치에서 작업 후 푸시
2. 깃허브에서 `Compare & pull request` 클릭
3. 제목과 설명 작성
4. `Create pull request` 클릭

#### PR 병합
1. Pull requests 탭
2. 해당 PR 선택
3. 코드 리뷰
4. `Merge pull request` 클릭
5. 커밋 메시지 확인 후 `Confirm merge`

---

## 06. 깃허브에서 소통하기

### 프로필 관리

#### 프로필 작성
1. 프로필 이미지 클릭
2. Settings
3. Public profile 수정:
   - Name
   - Bio
   - Company
   - Location
   - Website

#### 컨트리뷰션 그래프
- 깃허브 활동 내역을 시각화
- 초록색 진할수록 활동 많음
- 커밋, PR, 이슈 등 모든 활동 포함

### README 파일

#### README 작성
````markdown
# 프로젝트 제목

프로젝트 설명

## 설치 방법
```bash
npm install
```

## 사용법
```javascript
const app = require('./app');
app.start();
```

## 기여 방법

1. Fork
2. Branch 생성
3. Commit
4. Push
5. Pull Request
````

#### 마크다운 기본 문법
````markdown
# 제목 1
## 제목 2
### 제목 3

**굵게**
*기울임*
~~취소선~~

- 순서 없는 목록
1. 순서 있는 목록

[링크 텍스트](URL)
![이미지 설명](이미지 URL)

`인라인 코드`
```언어
코드 블록
```
````

### 오픈소스 기여

#### 기여 방법
1. **번역**: 문서를 한글로 번역
2. **문서화**: 사용법, 가이드 작성
3. **버그 수정**: 오류 발견 및 수정
4. **기능 제안**: 새로운 기능 제안

#### 기여 절차
1. 저장소 Fork
2. 브랜치 생성
3. 수정 작업
4. 커밋 및 푸시
5. Pull Request 생성

---

## 07. VS Code로 깃 다루기

### VS Code 깃 기능

#### 저장소 초기화
1. 폴더 열기
2. 소스 제어 아이콘 클릭
3. `리포지토리 초기화` 클릭

#### 스테이징과 커밋
1. 소스 제어 탭
2. 파일 옆 `+` 아이콘 (스테이징)
3. 메시지 입력 후 `✓` 클릭 (커밋)

#### 원격 저장소 연결
1. `...` → 원격 → 원격 추가
2. 원격 저장소 URL 입력
3. 이름 지정 (origin)

#### 푸시/풀
````
... → 풀, 푸시 → 다음으로 푸시/풀
````

### 브랜치 관리

#### 브랜치 생성
````
... → 분기 → 분기 만들기
````

#### 브랜치 전환
````
하단 상태바 브랜치명 클릭
````

#### 브랜치 병합
````
... → 분기 → 분기 병합
````

### 저장소 복제
````
리포지토리 복제 → URL 입력 → 저장 위치 선택
````

---

## 08. 깃허브 페이지 만들기

### 정적 웹사이트 호스팅

#### 이력서 사이트 만들기

**1. 저장소 준비**
````bash
# 예제 저장소 Fork
https://github.com/jjlaon/resume

# 로컬에 Clone
git clone https://github.com/YOUR-USERNAME/resume.git
````

**2. 파일 수정**
- `index.html`: 개인 정보 수정
- `bg.jpg`: 배경 이미지
- `pf.png`: 프로필 이미지

**3. GitHub Pages 활성화**
1. 저장소 → Settings
2. Pages
3. Source: main 브랜치 선택
4. Save

**4. 사이트 주소**
````
https://USERNAME.github.io/REPO-NAME
````

### Jekyll 블로그

#### Jekyll 테마 사용

**1. 저장소 이름 규칙**
````
USERNAME.github.io
````

**2. Jekyll 테마 Fork**
````bash
# 예: jekyll-now
https://github.com/barryclark/jekyll-now
````

**3. 기본 설정 (_config.yml)**
````yaml
name: Your Name
description: Your Description
url: https://username.github.io

# SNS 링크
footer-links:
  github: username
  twitter: username
````

**4. 포스트 작성**
````
파일명: _posts/YYYY-MM-DD-title.md

내용:
---
layout: post
title: Post Title
---

포스트 내용...
````

**5. 이미지 추가**
````markdown
![이미지 설명](/images/filename.png)
````

#### 추천 Jekyll 테마 사이트
- https://github.com/topics/jekyll-theme
- http://jekyllthemes.org/
- https://jekyllthemes.io/
- https://jekyll-themes.com/

---

## NEW. 깃허브 최신 기능

### GitHub Codespaces

**클라우드 개발 환경**

#### 사용 방법
1. 저장소에서 `Code` 클릭
2. `Create codespace on main`
3. VS Code 웹 에디터 실행
4. 바로 개발 가능

#### 장점
- 설치 불필요
- 어디서나 접속
- 일관된 개발 환경

### GitHub.dev

**간편한 웹 편집기**

#### 접근 방법
````
1. 저장소에서 . (마침표) 키 누르기
2. github.com을 github.dev로 변경
````

#### 기능
- 파일 수정
- 커밋
- 변경사항 비교
- README 미리보기

### GitHub Copilot

**AI 코드 추천 서비스**

#### 설치
1. VS Code 확장 검색: `copilot`
2. GitHub Copilot 설치
3. GitHub 계정 연결

#### 사용법
````javascript
// 주석으로 원하는 기능 설명
// display hello world

// Tab 키로 제안 수락
// Alt + [ / ] 로 다른 제안 탐색
````

#### 기능
- 코드 자동 완성
- 함수 생성
- 주석 자동 작성
- 여러 제안 제공

---

## 🎯 빠른 참조

### 자주 쓰는 명령어
````bash
# 상태 확인
git status

# 스테이징
git add .

# 커밋
git commit -m "message"

# 푸시
git push

# 풀
git pull

# 로그
git log --oneline

# 브랜치
git branch
git switch <branch>

# 병합
git merge <branch>
````

### 깃 워크플로우
````
1. git pull           (최신 상태 유지)
2. 파일 수정
3. git add .
4. git commit -m ""
5. git push
````

### 협업 워크플로우
````
1. Fork 또는 Clone
2. 브랜치 생성
3. 작업 및 커밋
4. 푸시
5. Pull Request
6. 코드 리뷰
7. 병합
````

---

## 📌 유용한 링크

- [Git 공식 문서](https://git-scm.com/doc)
- [GitHub 공식 가이드](https://guides.github.com/)
- [GitHub Skills](https://skills.github.com/)
- [Markdown 가이드](https://www.markdownguide.org/)
- [Git 시각화](https://git-school.github.io/visualizing-git/)

---

## 💡 팁

### 커밋 메시지 작성법
````
feat: 새로운 기능 추가
fix: 버그 수정
docs: 문서 수정
style: 코드 포맷팅
refactor: 코드 리팩토링
test: 테스트 코드
chore: 빌드, 설정 파일
````

### .gitignore 예시
````
# 운영체제
.DS_Store
Thumbs.db

# 에디터
.vscode/
.idea/

# 언어별
node_modules/
__pycache__/
*.pyc

# 환경 설정
.env
config.json
````

### 트러블슈팅

**푸시 거부됨**
````bash
git pull --rebase
git push
````

**병합 충돌**
````bash
# 충돌 파일 수정 후
git add .
git commit
````

**커밋 실수**
````bash
# 마지막 커밋 수정
git commit --amend

# 커밋 취소
git reset HEAD^
````

