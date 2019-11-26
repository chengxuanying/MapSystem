<p align="center">
<!--
  <a href="http://lcui.org/">
    <img src="https://lcui.lc-soft.io/static/images/lcui-logo-lg.png" alt="" width=72 height=72>
  </a>-->
  <h3 align="center">Map System</h3>
  <p align="center">
    A full-stack end-to-end road retrieval system.
  </p>
  <p align="center">
    <img src="https://img.shields.io/badge/python-3.6%20%7C%203.7-blue.svg" alt="py37">
    <a href="http://opensource.org/licenses/MIT"><img src="https://img.shields.io/github/license/lc-soft/LCUI.svg" alt="License"></a>
    <img src="https://img.shields.io/github/repo-size/chengsyuan/MapSystem.svg" alt="Repo size">
    <img src="https://img.shields.io/github/languages/code-size/chengsyuan/MapSystem.svg" alt="Code size">
  </p>
</p>

## System Architecture

<img src="backend/assets/docs1.png" alt="docs1" width="70%" />

## Demo

### Road Retrieval

![readme2](resource/readme2.gif)

### Algorithm Analysis
![readme1](resource/readme1.gif)


## Online Demo

We provide a online demo in a 1core-512Mb virtual machine.
Open http://144.202.78.149:5000/

## Usage

### Docker
```bash
docker build .
docker run -p 5000:5000 <id>
```

#### Open http://127.0.0.1:5000/

### Or You can run on your own

#### Clone Project

```bash
git clone https://github.com/chengsyuan/MapSystem.git
cd MapSystem
```

#### Compiler cpp backend

```bash
cd cpp_backend && cmake CMakeLists && make && cp ./cpp_backend ../backend/
```

#### Run flask (web server)

```bash
cd ../backend && pip install flask && python app.py
```

#### Open http://127.0.0.1:5000/

## About

This software (Map System) is an coursework for "Internship" and the instructor is Jianguang, Wu

```
Author: Chengxuan Ying(@chengsyuan), Ting yi Yu(@paranoiall) and Junwen Huang(inkevin).
Last Update: 11.26.2019
```
