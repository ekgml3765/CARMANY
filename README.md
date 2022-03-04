## 🚘 CARMANY 카매니


- **프로젝트명**: CARMANY 카매니
- **슬로건:** 자동차 거래 시스템
- **개발 기간**: 22.02.25~ 22.03.03 (1주)
- **개발 환경**: C, C++, Raspbian, GitHub
- **공동 문서**: https://splashy-twill-960.notion.site/e0fde5eadcde4fec8367db233b7a00fc



<br>


## 개발 및 구동 환경


 [ **해당 프로젝트가 구현된 환경 ]** 

- **Linux raspberrypi 4.4.34+ #3 Thu Dec 1 14:44:23 IST 2016 armv6l GNU/Linux**

```bash
//구동환경 체크

<br>

uname -a
```

**[ 해당 프로젝트에 사용된 컴파일러 ]**

- **g++ (Raspbian 8.3.0-6+rpi1) 8.3.0**
- **g++ 컴파일러로 컴파일 및 빌드해주세요.**

```bash
//g++ 설치 및 컴파일러 버전 확인

g++ --version
```

**[ 공유 라이브러리 사용을 위한 환경 ]**

- **해당 프로젝트는 공유라이브러리를 사용해 링크하고 있습니다.**
- **공유라이브러리 링크를 위한 준비 사항은 아래와 같습니다**.

```bash
1. 실행 환경에 **pi** 라는 사용자를 생성해주세요.
2. pi 사용자의 홈 디렉토리(/home/pi/) 아래에 lib 폴더를 생성해주세요.
	=> mkdir /home/pi/lib

3. LD_LIBRARY_PATH가 설정되어 있지 않다면, .bashrc에 아래 문장을 추가해주세요!
   // .bashrc에 진입
		vi .bashrc
	 // 맨 아래에 해당 문장 추가
		export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/pi/lib
```


<br>


## 1.  테스트를 위한 폴더 생성


- **원활한 테스트를 위해 *“새로운 폴더”* 를 하나 생성해주세요!**
- **이후 해당 폴더로 진입해주세요.**

```bash
//폴더 생성하기
mkdir 원하는 폴더명

//해당 폴더로 진입하기
cd 폴더명
```

## 2. project_11.tar.gz 압축 풀기


- **테스트를 위해 생성한 폴더 안에서 *project_11.tar.gz* 압축을 풀어주세요.**

```bash
//gzip으로 압축된 파일 풀기
gunzip 11조_project.tar.gz

//tar로 묶인 아카이브 풀기
tar xvf 11조_project.tar
```

- **압축을 풀고 난 후 ls 명령어로 아래와 같은 파일과 폴더들이 나오는 지 확인해주세요.**

```bash
ls

//출력되어야할 폴더와 파일 목록
//11조_project.tar appSrc header library Makefile
```

## 3. make를 활용한 컴파일 및 빌드하기


- **make 명령으로 컴파일과 빌드를 진행합니다.**

```bash
make
```

## 4. appSrc 폴더로 들어가 main 파일 실행하기


- **appSrc 폴더로 진입한 뒤 main를 실행시킵니다.**
