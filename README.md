# Ray-Tracing
[简单的光线追踪器](https://github.com/impulses-1/Ray-Tracing)

# 运行项目
mac/linux 环境下,控制台运行 build.sh  

windows 环境下,通过git的命令行工具运行 build.sh

## mac 环境运行项目示例
```shell
cd desktop/ray-tracing #进入项目文件
chmod +x build.sh      #获得权限
./build.sh             #执行build.sh
```

# 效果说明
程序输出的是.ppm格式的图片
因为markdown不能展示.ppm,所以效果图都转成了.png格式

## 0.1 Get A Image
![0.1 effect](images/0.1.png)

## 0.2 Ray Into Scene
![0.2 effect](images/0.2.png)

## 0.3 Add A Sphere
![0.3 effect](images/0.3.png)

## 0.4 Shading With Surface Normals
![0.4 effect](images/0.4.png)

## 0.5 Render Multiple Objects
![0.5 effect](images/0.5.png)

## 0.6 Antialiasing
>宽: 711, 高: 400 
>每像素随机在周围采样100次, 时间花费: 7.8s

![0.6 effect](images/0.6.png)

## 0.7 Diffuse Materials

### 0.7.0 Simple Reflection 
![0.7.0 effect](images/0.7.0.png)

### 0.7.1 True Lambertian Reflection
![0.7.1 effect](images/0.7.1.png)

### 0.7.2 Hemisphere Reflection
![0.7.2 effect](images/0.7.2.png)

# 参考
1. [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)
2. [Games 101-现代计算机图形学入门-闫令琪](https://www.bilibili.com/video/BV1X7411F744?p=1)
3. [Software Renderer](https://github.com/zauonlok/renderer)