# glImshow(じーえるあいえむしょう)
opencvの画像(Mat)とopenglの描画を連携して高速な描画を行うちょっとしたコード。

## まえがき
opencvの描画が遅いからopenglの描画機能を使って高速に描画すると幸せだねって
[記事](http://neno-garden.com/blog/2017/12/11/drawspeedtest/)をひと昔前に書いたんだけど。
どうもその記事だけやたら閲覧されているので、コード整理して使いやすくしてみた。

VideoCapture使うならmain.cppの中にあるdisplay,ketbord,mainLoopの関数の中身にやりたい処理書けばいい感じだけど。速度気になった人は使ってなさそう。  
プログラマブルなカメラ使うならmain()の最初にカメラの初期化とかそういうこと書くと幸せになれるでしょう(たぶん)。

## 外部ライブラリ
OpenCV3.4.0  
freeglut3.1.0  

dll(so?)をビルドしておいてリンクさせるとよいでしょう。

## 環境
windows10 1709で動作は確認。

## 動かし方
ビルドして動かせば内臓してるカメラか接続しているwebカメラを描画するサンプルが動くと思います。あとは煮るなり焼くなり。
