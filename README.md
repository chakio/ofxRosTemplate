[![MIT licensed](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
# ofxRosTemplate
![result](https://github.com/chakio/ofxRosTemplate/blob/master/media/ofxRosTemplate.gif)  
openFrameworks上でROSを使用します。

## Description
ROSで開発をすすめる際、RVizのみでは描画したいデータが描画しきれない場合が多々あると思います。  
openFrameworks上でROSが使用できるようにすることで、ROS上のデータをopenFrameworksで描画することを実現します。

## Environment
* OS : Ubuntu 16.04
* ROS : kinetic  
* openFrameworks :   v0.10.0

* visualstudio code  

## Setup

* [ubuntuでopenFrameworksの開発環境を構築する](https://qiita.com/nnn_anoken/items/b6834379e2eeeeae6793)
* [vscodeでopenFrameworksの開発を行う環境構築](http://cvl-robot.hateblo.jp/entry/2018/01/24/113956)
* [openFrameworksのROS対応](http://cvl-robot.hateblo.jp/entry/2018/01/24/130246)  
これらのサイトに大変お世話になりました。  

### ubuntuにおけるopenFrameworksの開発環境のセットアップ 
 #### openFrameworksのダウンロードと展開  
    wget http://openframeworks.cc/versions/v0.10.0/of_v0.10.0_linux64_release.tar.gz
    tar xvfz of_v0.10.0_linux64_release.tar.gz    
    mv of_v0.10.0_linux64_release of_v0.10.0_linux64    
    cd of_v0.10.0_linux64/scripts/linux/ubuntu        
 #### 必要なライブラリのインストール
    sudo ./install_dependencies.sh
    sudo ./install_codecs.sh
 ####  openFrameworksのコンパイル
    cd of_v0.10.0_linux64/scripts/linux
    ./compileOF.sh -j3

### [VSCodeのインストール](http://cvl-robot.hateblo.jp/entry/2018/01/24/113956)
 #### テンプレートのインストール
    cd oF用のワークスペース/
    git clone https://github.com/chakio/ofxRosTemplate.git
 ダウンロードしたテンプレートがひとつのプロジェクトになります。
 テンプレートを改変しながら開発を進めてください。
 vscode_oF.code-workspace をvscodeで開きます。  
 binの中に、ofAppやmainなどがあります。  
 buildなどはvscodeで行います。（Ctrl + Shift + b）
 正しくbuildを行うため以下の設定が必要です。  
 * ofの場所を教えてあげる  
     Makefileの９行目 OF_ROOTのパスを正しく設定
 * buildの設定をReleaseにする  
     tasks.jsonをvscodeのエクスプローラで検索  
     16行目を"Release"に変更
 これでbuildが通るはずです。

## Useage
* ```roscore```  
カレントディレクトリを  
``` oF用のワークスペース/ofxRosTemplate/```  
に移動した後に  
* ```./bin/ofRosTemplate```