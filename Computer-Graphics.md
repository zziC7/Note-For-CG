# Introduction to Computer Graphics 现代计算机图形学入门

> By 闫令琪  UC Santa Barbara  https://www.bilibili.com/video/BV1X7411F744

## Lecture 1 : Overview of Computer Graphics

- What is CG?

- Why study CG?

  -- Applications

  -- Fundamental Intellectual

  -- Technical Challenges

- Course Topics

- Course Logistics



**What is CG?**

The use of computers to synthesize and manipulate visual information.



**Applications:**

1、Video Games -- e.g. 只狼  画面足够亮的游戏，往往质量较高(渲染中的全局光照做的比较好)

Borderlands 3 无主之地 卡通风格(怎么实现?)

2、Movies -- The Matrix(黑客帝国)  Avatar(阿凡达)

特效(special effects)通过图形学实现(特效的应用并不难,平时见得少,做的粗糙也没太大关系哈哈哈哈) Rendering 

3、Animations(动画) -- Zootopia(疯狂动物城)

Frozen 2(冰雪奇缘2)

4、Design -- CAD(Computer Aided Design)计算机辅助制图

Ikea(宜家) 75% of catalog is rendered imagery

5、visualization 可视化

6、Virtual Reality 虚拟现实VR:看到的东西都是电脑生成的

Augmented Reality 增强现实AR:可以看到现实的东西+电脑增加的部分

7、Digital Illustration 数码插画 -- Photoshop

8、Simulation 模拟 -- 沙尘暴、黑洞

9、GUI:Graphics User Interfaces 图形用户接口

10、Typography 字体设计: 点阵/矢量



**Course Topics:**

- Rasterization 光栅化 OpenGL/Shader如何运作
- Curves and Meshes 曲线与曲面
- Ray Tracing 光线追踪
- Animation / Simulation 动画/模拟

CG ≠ CV Deep Learning

CV是处理现实问题，CG是重现现实世界

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210716141918999.png" alt="image-20210716141918999" style="zoom:67%;" />



## Lecture 2 : Review of Linear Algebra

- 向量(矢量) Vectors

Vector Normalization   <img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210716214254496.png" alt="image-20210716214254496" style="zoom:50%;" /> a-hat

Vector Addition

**Vector Multipication:**

Dot(scalar) Product 点乘 <img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210716215519728.png" alt="image-20210716215519728" style="zoom:50%;" />

在图像中可以找到两个向量的夹角；

找一个向量在另一个向量上的投影；

b-b.perp可以measure两个向量接近的程度；

determine forward/backward；



Cross product 叉乘

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210716222812690.png" alt="image-20210716222812690" style="zoom:50%;" />

Determine left/right

Determine inside/outside



- 矩阵 Matrices

Non-commutative

Associative and distributive



## Lecture 3 : Transformation

- Why study transformation
- 2D trans: rotation, scale, shear
- Homogeneous coordinates
- Composing transforms
- *3D trans



**Why study trans?**

-- Modeling 模型变换

-- Viewing 视图变换



**1、Scale:缩放变换**

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210716232413949.png" alt="image-20210716232413949" style="zoom: 33%;" />

**2、Reflection:反射**

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210716232715261.png" alt="image-20210716232715261" style="zoom:33%;" />

**3、Shear:切变**

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210717161520423.png" alt="image-20210717161520423" style="zoom:33%;" />

**4、Rotate:旋转**

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210717162909024.png" alt="image-20210717162909024" style="zoom:33%;" />

以上都是线性变换:能写成 X’ = MX的形式(M是同维度的矩阵)



**齐次坐标 Homogeneous coordinates**

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718013526330.png" alt="image-20210718013526330" style="zoom:33%;" />

平移(Translation)变换：不能写成X’ = MX的形式

**但是!**我们不希望平移成为一种special case

解决方法:引入齐次坐标(what’s the cost? -- trade-off)

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718013950144.png" alt="image-20210718013950144" style="zoom:33%;" />

加入三维坐标:点增加一个1,向量增加一个0

**向量是0,点是1的原因:**

①保护向量的平移不变性,向量经过左边这个矩阵的乘法之后仍然是(x,y,0)而不是x+t<sub>x</sub>;

②点是1的话, point-point=0,符合point-point=vector

- vector + vector = vector
- point - point = vector
- point + vector = point 
- point + point = 这两个点的中点(根据下面的法则)

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718014700891.png" alt="image-20210718014700891" style="zoom:33%;" />

w只有0和1有意义，如果不是0/1，三个数都同除w



**Affine Transformation(仿射变换):**

使用齐次坐标之后，只需要用一个矩阵即可

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718014846073.png" alt="image-20210718014846073" style="zoom:33%;" />

Affine map = linear map + translation **先线性变换再平移**



齐次坐标下的其他变换：

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718015009493.png" alt="image-20210718015009493" style="zoom:33%;" />

代价(cost):增加了一个维度(但是很多是0,代价不大)



**Inverse Transform 逆变换**:

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718091809563.png" alt="image-20210718091809563" style="zoom:33%;" />



**Composing Transforms 组合变换:**

变换的顺序很重要(矩阵乘法无交换律)

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718092129431.png" alt="image-20210718092129431" style="zoom:33%;" />

变换的应用顺序是**从右到左**



## Lecture 4 : Transformation cont.

- 3D transformations

- Viewing(观测) transformation

  -- View(视图)/ Camera transformation

  -- Projection(投影) transformaiton

  ​	-- Orthographic(正交) projection

  ​	-- Perspective(透视) projection



**3D transformations:**

原理同二维:

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718095901674.png" alt="image-20210718095901674" style="zoom:33%;" />



三维中的仿射变换(同样是先线性变换再平移):

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718095929004.png" alt="image-20210718095929004" style="zoom:33%;" />



三维的缩放&平移:

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718100047062.png" alt="image-20210718100047062" style="zoom:33%;" />



三维的旋转:

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718100106969.png" alt="image-20210718100106969" style="zoom:33%;" />



任意旋转:<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718100729134.png" alt="image-20210718100729134" style="zoom:33%;" />

欧拉角<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718100840523.png" alt="image-20210718100840523" style="zoom:33%;" />

**罗德里格斯旋转公式:**

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718101042292.png" alt="image-20210718101042292" style="zoom:40%;" />



三维空间投影到二维平面:

**View / Camera transformation:**

- What is view transformation?

- Think about how to take a photo?

  Find a good place and arrange people(**model** transformation)

  Find a good angle to put the camera(**view** transformation)

  Cheese! (**projection** transformation)

↑MVP变换



Define the camera:

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718150900823.png" alt="image-20210718150900823" style="zoom:33%;" />

为了方便,把camera平移到原点,同时保持camera和物体的相对位置不变

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718151445405.png" alt="image-20210718151445405" style="zoom:33%;" />

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718151524601.png" alt="image-20210718151524601" style="zoom:50%;" />

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718151551166.png" alt="image-20210718151551166" style="zoom:50%;" />

至此,MV变换已经完成,为之后的P变换奠定基础!





**Projection Transformation(投影变换):**

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718193751281.png" alt="image-20210718193751281" style="zoom:50%;" />

- Perspective projection 透视投影(近大远小)

- Orthographic projection 正交投影(一叶障目)  相机无限远

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718194437472.png" alt="image-20210718194437472" style="zoom: 50%;" />

**更加正规的方法(Bounding Box):**

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718195454062.png" alt="image-20210718195454062" style="zoom: 50%;" />

先找到视野的Bounding Box的边界

left,right; top,bottom; near,far.

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718195536234.png" alt="image-20210718195536234" style="zoom:50%;" />

先平移到中心，再缩放到[-1,1]区间。

**注意:**为了保证右手系,摄像机指向-Z,所以近的物体Z坐标大,远的物体Z坐标小。



**Perspective projection(透视投影):**

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718200622443.png" alt="image-20210718200622443" style="zoom:50%;" />

把远平面“挤”成近平面,再作正交投影。

条件:近平面、远平面、远平面中心在挤压过程中不变。

挤压的计算：相似三角形

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718201112385.png" alt="image-20210718201112385" style="zoom:50%;" />

**推导M<sub>persp->ortho</sub>:**

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718201936449.png" alt="image-20210718201936449" style="zoom:50%;" />

推导第三行：

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718202004698.png" alt="image-20210718202004698" style="zoom:50%;" />

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718202105554.png" alt="image-20210718202105554" style="zoom:50%;" />

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718202707251.png" alt="image-20210718202707251" style="zoom:50%;" />

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210718202806861.png" alt="image-20210718202806861" style="zoom:50%;" />

**Transformation总结思维导图:**

<img src="C:\Users\86188\AppData\Roaming\Typora\typora-user-images\image-20210719003450979.png" alt="image-20210719003450979" style="zoom:50%;" />

## Lecture 5 : Rasterization 1 (Triangles)

三角形的光栅化

- Finishing up viewing

  -- Viewport transformation

- **Rasterization**

  **-- Different raster displays**

  **-- Rasterizing a triangle**

- Occlusions and Visibility

定义frustum(视锥)的两个概念:

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210719143421435.png" alt="image-20210719143421435" style="zoom:50%;" />

- **aspect ratio**  宽高比
- **field-of-view (fovY)**  视场角

概念的相互转化：

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210720163444478.png" alt="image-20210720163444478" style="zoom:50%;" />

定义一个视锥,只需要定义其宽高比和视场角。



投影变换得到了[-1,1]的立方体,怎么画到屏幕上?--光栅化

**What is screen?**

- An array of pixels
- Size of the array: resolution 像素的多少--分辨率
- A typical kind of raster display 光栅成像设备

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210720164253648.png" alt="image-20210720164253648" style="zoom:50%;" />



**Viewport transformation 视口变换:**<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210720164640673.png" alt="image-20210720164640673" style="zoom:50%;" />

**Next: Rasterizing Triangles into Pixels.**

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210720170454895.png" alt="image-20210720170454895" style="zoom:50%;" />

- **A Simple Approach: Sampling(采样)**

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210720171213012.png" alt="image-20210720171213012" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210720171345532.png" alt="image-20210720171345532" style="zoom:50%;" />

对三角形采样:判断像素中心是否在三角形内

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210720171429123.png" alt="image-20210720171429123" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210720171437686.png" alt="image-20210720171437686" style="zoom:50%;" />

如何判断这个点是否在三角形内?--向量的叉乘

(Edge cases -- 边界自定义,本课不做处理)

![image-20210720173416699](F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210720173416699.png)

问题:Aliasing(Jaggies) 走样(锯齿) -- 信号的采样率不够高



## Lecture 6 : Rasterization 2 (Antialiasing and Z-Buffering)

- **Antialiasing 反走样(抗锯齿)**
- Z-Buffering 深度缓冲

Today:

- **Antialiasing**

  -- Sampling theory

  -- Antialiasing in practice

- Visibility / occlusion

  -- Z-buffering
  
  

**Artifacts(瑕疵) due to sampling - “Aliasing”**

- Jaggies - 锯齿
- Moire - 摩尔纹
- Wagon wheel effect - 车轮效应
- ……

**本质:**信号变化速度过快,而采样的频率太低



先对信号进行模糊(blurring),滤波(pre-filter),再采样,可以减少锯齿化。(不能先采样再滤波)

Frequency Domain频域

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210724101441800.png" alt="image-20210724101441800" style="zoom:50%;" />

把一个函数分解为不同频率的段，并显示出来。



**滤波:**

Filtering = getting rid of certain frequency contents 去掉一些特定的频率



傅里叶变换: 时域->频域

**①正常图片:**

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210725142743112.png" alt="image-20210725142743112" style="zoom:50%;" />

**②高通滤波:**

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210725142800781.png" alt="image-20210725142800781" style="zoom:50%;" />

**③低通滤波:**

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210725142824870.png" alt="image-20210725142824870" style="zoom:50%;" />

卷积定理:时域卷积=频域乘积

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210725143809546.png" alt="image-20210725143809546" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210725143800248.png" alt="image-20210725143800248" style="zoom:50%;" />

卷积核(滤波器)越大,频率越低,图像越模糊。



Sampling = Repeating Frequency Contents

采样=重复频率内容



Aliasing = Mixed Frequency Contents

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210729095240603.png" alt="image-20210729095240603" style="zoom:50%;" />



**Antialiasing 反走样:**

1、*Increase sampling rate 换个显示器

**2、先做模糊(低通滤波，过滤高频信息)再做采样**

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210729095831622.png" alt="image-20210729095831622" style="zoom:50%;" />

减小频谱的覆盖范围

**怎么变模糊？**

寻找一个一定大小的低通滤波器进行卷积操作

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210729100707157.png" alt="image-20210729100707157" style="zoom:50%;" />

怎么算出一个像素被覆盖的面积?

**Antialiasing By Supersampling(MSAA)**

MSAA = Multi Sample Antialiasing

是反走样的近似，不能完全解决走样

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210729101125564.png" alt="image-20210729101125564" style="zoom:50%;" />

把一个像素再分成小像素，判断是否在三角形内

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210729101452711.png" alt="image-20210729101452711" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210729101302619.png" alt="image-20210729101302619" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210729101309448.png" alt="image-20210729101309448" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210729101320559.png" alt="image-20210729101320559" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210729101327196.png" alt="image-20210729101327196" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210729101333158.png" alt="image-20210729101333158" style="zoom:50%;" />

- 至此，模糊操作做完了，再进行采样即可(还是这个结果)
- MSAA进行的是模糊操作(采样操作已经隐含在里面了)
- 并没有提高采样率，只是对三角形的覆盖面积进行近似



**但是!**No free lunch! What’s the cost of MSAA?

- 放置了更多的点，增加了计算量。



**Milestones(personal idea):**

- FXAA(Fast Approximate AA) 快速近似抗锯齿(后期图像处理抗锯齿，速度很快，效果也好)
- TAA(Temporal AA) 复用上一帧的图像(同一像素的不同位置)，即将没有MSAA的图像分布在时间上



**Super resolution / super samling:**

超分辨率≠抗锯齿，但本质相似

- From low resolution to high resolution
- Essentially still “not enough samples” problem 图片虽然分辨率高，但是采样不足
- DLSS(Deep Learning Super Sampling) 图片拉大后信息缺失，用深度学习进行“猜”





## Lecture 7 : Shading 1 (Illumination, Shading and Graphics Pipeline)

- Visibility / occlusion

  -- Z-buffering 深度缓冲

- Shading

  -- Illumination & Shading

  -- Graphics Pipeline



Painter’s Algorithm 画家算法:先画远处的，进行光栅化，再画近处的进行覆盖。

特殊情况:存在互相遮挡的情况，无法定义深度关系，也无法使用画家算法。

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210729182422419.png" alt="image-20210729182422419" style="zoom:50%;" />

由此，引入Z-Buffer.

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210729182758277.png" alt="image-20210729182758277" style="zoom:50%;" />

Z小则近，大则远。与Transform里面的不同(为了简化)

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210729200447966.png" alt="image-20210729200447966" style="zoom:50%;" />

同步生成两幅图 color(FrameBuffer) & depth(Z-Buffer)

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210729200739984.png" alt="image-20210729200739984" style="zoom:50%;" />

注意:Z-Buffer 无法处理透明物体



**Shading 着色:**

Shading:The process of applying a material to an object.

(不同材质:木头、铅球等不同材质与光源有不同的互动)



A Simple Shading Model(**Blinn-Phong** Reflectance Model)

- 高光
- 漫反射
- 环境光

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210730121619467.png" alt="image-20210730121619467" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210730122034912.png" alt="image-20210730122034912" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210730122202758.png" alt="image-20210730122202758" style="zoom:50%;" />

只考虑Shading point 自己，不考虑其他情况，即只着色，但没有阴影。 shading ≠ shadow!



Lambert’s cosine law :

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210730122516268.png" alt="image-20210730122516268" style="zoom:50%;" />



<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210730123037484.png" alt="image-20210730123037484" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210730123353006.png" alt="image-20210730123353006" style="zoom:50%;" />

漫反射和观测方向没有关系(因此公式里没有v)

L<sub>d</sub>:漫反射的光强

k<sub>d</sub>:漫反射系数(Shading point 的颜色，决定吸收了哪些光，黑色为0(全吸收了)，白色为1)





## Lecture 8 : Shading 2 (Shading, Pipeline and Texture Mapping)

- Blinn-Phong reflectance model

  -- Specular and ambient terms

- Shading frequencies

- Graphics pipeline

------------------------------------------------------------------------

**Blinn-Phong reflectance model:**

1. Specular
2. Diffuse  // 上节课讲过，今天讲另外两个
3. Ambient

Specular terms:

物体表面比较光滑，光线接近镜面反射

观察方向和镜面反射方向接近(v和R足够接近)

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807150154089.png" alt="image-20210807150154089" style="zoom:50%;" />

引入半程向量(bisector)h:

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807150403534.png" alt="image-20210807150403534" style="zoom:50%;" /> 

v和R接近 就是 n和h接近

- Phong模型：用v和R的接近程度
- Blinn-Phong模型：用n和h的接近程度(改进)，半程向量比较好算

指数p:减少容忍度，用来控制高光的大小，通常取100~200

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807150830659.png" alt="image-20210807150830659" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807151000867.png" alt="image-20210807151000867" style="zoom:50%;" />



Ambient Term:

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807151123605.png" alt="image-20210807151123605" style="zoom:50%;" />

环境光：与光源方向、观测方向、法线都无关，是一个常数(某种颜色)。保证没有一个地方完全是黑的

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807151251398.png" alt="image-20210807151251398" style="zoom:50%;" />

着色过程完成!



**Shading Frequencies:**

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807152045142.png" alt="image-20210807152045142" style="zoom:50%;" />

1、Flat shading 逐三角形

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807152336727.png" alt="image-20210807152336727" style="zoom:50%;" />

2、Gouraud shading 高洛德 逐顶点

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807152422351.png" alt="image-20210807152422351" style="zoom:50%;" />

3、Phong shading 逐像素

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807152509598.png" alt="image-20210807152509598" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807152722028.png" alt="image-20210807152722028" style="zoom:50%;" />

定义逐顶点的法线：

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807153305114.png" alt="image-20210807153305114" style="zoom:50%;" />

与这个点相关联的三角形的法线的简单平均/加权平均。

加权平均要更准确



定义逐像素的法线：

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807153434229.png" alt="image-20210807153434229" style="zoom:50%;" />

重心插值



**Graphics(Real-time Rendering) Pipeline:**

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807153854856.png" alt="image-20210807153854856" style="zoom:50%;" />

图形管线(一系列的操作):三维场景→二维图片

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807154118009.png" alt="image-20210807154118009" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807154124331.png" alt="image-20210807154124331" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807154131651.png" alt="image-20210807154131651" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807154137419.png" alt="image-20210807154137419" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807154448102.png" alt="image-20210807154448102" style="zoom:50%;" />



**Shader着色器(OpenGL):**

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807154905964.png" alt="image-20210807154905964" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807155034741.png" alt="image-20210807155034741" style="zoom:50%;" />

Shader体验网站:https://www.shadertoy.com/view/ld3Gz2



现代图形学发展：

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807155645873.png" alt="image-20210807155645873" style="zoom:50%;" />

UE4 快速渲染

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807155701614.png" alt="image-20210807155701614" style="zoom:50%;" />

GPU快速发展



**Texture Mapping:纹理映射**

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807160137065.png" alt="image-20210807160137065" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807160302557.png" alt="image-20210807160302557" style="zoom:50%;" />

定义：三维物体的表面是二维的，相当于贴图(一张图贴到三维模型上去)

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807160431841.png" alt="image-20210807160431841" style="zoom:50%;" />

纹理坐标：

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807160831790.png" alt="image-20210807160831790" style="zoom:50%;" />

规定u,v∈[0,1]，三角形每个顶点都对应一个(u,v)

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210807161120153.png" alt="image-20210807161120153" style="zoom:50%;" />

无缝衔接纹理的绘制(难度很大)，复用时看不出缝隙





## Lecture 9 : Shading 3 (Texture Mapping cont.)

- Barycentric coordinates 重心坐标(插值)
- Texture queries 
- Applications of textures

------------------------------------------------------------------------

**Interpolation Across Triangles:Bartcentric Coordinates**

1、为什么要做插值？

- 利用三角形顶点的值，得到内部的值(平滑过渡)

2、插值要得到什么？

- 纹理坐标，颜色，法线……

3、怎么做插值？

- 重心坐标

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808133213851.png" alt="image-20210808133213851" style="zoom:50%;" />

(α,β,γ)均为非负

可以通过面积计算：

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808133700307.png" alt="image-20210808133700307" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808133958318.png" alt="image-20210808133958318" style="zoom:50%;" />

利用重心坐标进行插值计算：

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808134124240.png" alt="image-20210808134124240" style="zoom:50%;" />

注意：投影之后重心坐标会发生变化!



**Applying Textures:**

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808134635264.png" alt="image-20210808134635264" style="zoom:50%;" />

**问题:Texture Magnification(What if the texture is too small?)**

双线性插值：找临近的4个点

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808135421792.png" alt="image-20210808135421792" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808135659582.png" alt="image-20210808135659582" style="zoom:50%;" />



**What if the texture is too big?**

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808140300750.png" alt="image-20210808140300750" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808140501169.png" alt="image-20210808140501169" style="zoom:50%;" />



**Mipmap (Allowing(fast, approx., square) range queries)**

近似的方形范围查询

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808142916225.png" alt="image-20210808142916225" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808142929438.png" alt="image-20210808142929438" style="zoom:50%;" />

内存多花销了1/3

1 --> 4/3



计算在Mipmap的第几层:

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808144016258.png" alt="image-20210808144016258" style="zoom:50%;" />

离得近，细节充足，在低层查询；

离得远，细节模糊，在高层查询。

层与层之间可以用三线性插值：

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808144257451.png" alt="image-20210808144257451" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808144558617.png" alt="image-20210808144558617" style="zoom:50%;" />

Mipmap在远处出现了Overblur(Mipmap只能处理正方形，无法处理特殊形状)

Better:各向异性过滤(可以处理矩形，但不能处理特殊形状)

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808144701502.png" alt="image-20210808144701502" style="zoom:50%;" />

<img src="F:\Git\CS\Computer-Graphics\Computer-Graphics.assets\image-20210808145034419.png" alt="image-20210808145034419" style="zoom:50%;" />

