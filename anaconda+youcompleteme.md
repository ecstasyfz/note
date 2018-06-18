# YouCompleteMe+Anaconda混合安装

最近从头开始配vim，自己平时要用C++和conda，结果在安装的时候被坑了好久(;´Д`)．

普通安装并不是什么问题，但是跟anaconda配合的时候各种乱七八糟报错，具体就不贴了，首先Github里面作者直接说的是．

> Valloric commented on Nov 19, 2014
> Only the official Python distributions are supported. Thank you for reporting this though; hopefully it will help people searching on Google.

嘛，弄了好久最后成功是成功了．总之这篇文章试着重新整理下YCM的安装过程，然后翻译一下文档 ( ´ー`)

---

####　下载源码

因为自己是用的Vim-Plug，教程就按着这么写下去了，用Vundle和Pathogen的自己把vimrc的安装和之后的一些路径改一下．

首先在`.vimrc`里面加入

```viml
Plug 'Valloric/YouCompleteMe'
```

重新打开vim后执行

```viml
:PlugInstall
```

稍等很长一段时间源码就会被下载到`~/.vim/plugged/YouCompleteMe`里面了

#### 环境准备

按照官方README的说法cmake是需要的，python3也是需要的．关键是自己的vim，需要 `Version > 7.4.1578 with Python2 or Python3 support`(目前) ．

可以通过`vim --version`查看当前安装的vim，注意到里面如果Feature included有`+python3`应该就没问题了，没有的情况可以自行编译vim或者最简单的直接装个Gvim|∀` )

---

#### 自动安装

直接执行

```shell
~/.vim/plugged/YouCompleteMe/install.py
```

进行安装．

需要C语言支持的可以加入`--clang-completer`，也就是

```shell
~/.vim/plugged/YouCompleteMe/install.py --clang-completer
```

其他语言支持C#，Go，TS，JS，Rust，java。但是我压根儿就不会这些，所以也就不测试了。

但是真的别了，我也不知道为为什么，各种报错．



