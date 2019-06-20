## git command 정리

#### git 버전 확인

>  git --version 



#### git 저장소 상태 체크

> git status

#### git 이름과 이메일 등록

> git config --global user.name = "Kong"
>
>  git config --global user.email = "gbd4789@naver.com"



#### 잘 설정됬는지 확인

> git config --list

![1561005519606](C:\Users\multicampus\AppData\Roaming\Typora\typora-user-images\1561005519606.png)

~~~
로컬 저장소는 git이 관리하는 3그루의 나무로 구성되어있음
첫번째 나무인 작업 디렉토리는 실제 파일들로 이루어져 있고,
두번째 나무인 인덱스는 준비영역의 역할을 하며,
세번째 나무인 헤드는 최종 확정본(커밋) 을 나타냅니다.

add를 하면 인덱스에 추가하는 것이고
commit을 하면 헤드에 추가하여 실제로 변경된 내용을 확정
push를 하여 원격저장소에 반영을 함.
~~~

#### 폴더를 로컬저장소로 지정

> git init

#### 인덱스에 추가

> git add .

#### 커밋

> git commit -m '메시지'



#### 기존의 git원격저장소(github 링크)와 연결 및 수정하는법

>git init
>
>git remote add origin https://github.com/ByungdooGong/AlgorithmStudy.git
>
>git clone https://github.com/ByungdooGong/AlgorithmStudy.git
>
>git pull origin master --allow-unrelated-histories
>
>git add .
>
>git commit -m 메시지
>
>git push origin master

- git clone url

  ```
  $git clone https://github.com/ByungdooGong/AlgorithmStudy.git
  ```

  - init-> remote add->fetch->merge절차를 한방에

  - 원격저장소에 있는 내용을 로컬 컴퓨터로 불러옴 

- git fetch remote명 branch명

  ```
  $ git fetch origin master
  ```

  - 원격저장소(remote)의 최신 변경사항을 가져옴 

- git fetch --all

  ```
  $ git fetch --all
  ```

  - 패치된 내용 보여줌

- git merge branch명 또는 버전키

  ```
  $ git merge master
  ```

  - fetch한 것을 현재 작업 중인 local branch(master)에 통합시킴

- git pull remote명 branch명

  ```
  $ git pull origin master
  ```

  - fetch와 merge를 한방에 수행

#### 그 외 유용한 함수

```
$ git remote
```

원격저장소 이름을 알려줌(origin)



```
$ git remote remove origin 
```

origin이라는 remote(원격저장소) 삭제



```
$ git remote -v
```

저장소를 확인할 수 있음 

![1561013475398](C:\Users\multicampus\AppData\Roaming\Typora\typora-user-images\1561013475398.png)

