
# 競技プログラミング　個人作業場所

## atcoder

### 環境構築

ojコマンドとaccコマンドを使うため、
下記サイトでインストールしておく
[参考サイト](https://zenn.dev/bun913/articles/573790d7e5b1a4)

下記、エイリアスを設定しておく

```
alias ojsubmit="acc s ./main.cpp"
alias ojtest="g++ -std=c++17 ./main.cpp; oj t -c \"./a.out\" -d tests/"
alias ojbuild="g++ -std=c++17 ./main.cpp"
alias addc++="cp ~template.cpp ./main.cpp"

alias addgo="cp ~template.go ./main.go"
alias ojtestgo="oj t -c \"go run ./main.go\" -d tests/"
```

### 問題のダウンロード

```
$ acc new abcxxx
```

### テストの実行

```
$ ojtest
```

### 提出

```
$ ojsubmit
```

### UnitTest(今は使ってない)

cppファイル内に#ifdefと#ifndefでコンパイルスイッチすれば、
競技用プログラミングにおいては都合が良さそう

g++ -std=c++17 main.cpp   -D DEBUG -I "../lest/include/" ; ./a.out

#### scons

$ scons --debug_build
