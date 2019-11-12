<template>

    <el-tabs tab-position="left">
        <el-tab-pane label="系统架构">
            <div style="margin-left: 30px;">
                <h2>系统架构</h2>

                <h3>系统架构图</h3>
                <p>下图是我们的系统架构图。我们的系统架构主要分为前端ui展示层，业务层，计算层，数据库，运行环境六部分。</p>
                <el-image src="dist/docs1.png" fit="contain" style="width: 80%;"></el-image>


                <p>其中，我们的前端又挨包括element ui，包括CSS，包括JavaScript以及我们美工，黄俊文童鞋，制作的图片。
                </p>
                <p>我们的展示层包括VUE引擎，包括Ajax，读取的是Restful API，也包括我们的Get请求。
                </p>
                <p>我们的业务层包括首页数据分析，数据检索，数据更新，排序比较和说明文档等内容。
                </p>
                <p>我们的计算层包括读写过程，数据缓存排序过程，自定义排序，JSON格式化等内容。
                </p>
                <p>我们的数据库读写老师给定的data格式二进制文件。
                </p>
                <p>我们的运行环境为Linux，当然同样可以运行在虚拟机环境中。
                </p>
                <p>我们的业务层和计算层之间实现了负载均衡。
                </p>
                <p>我们的展示层，业务层、计算层，对外提供端对端的服务。</p>
            
            </div>

        </el-tab-pane>

        <el-tab-pane label="前端">
            <div style="margin-left: 30px;">
                <h2>前端</h2>
                <h3>前端图</h3>
                <el-image src="dist/qd.jpg" fit="contain" style="width: 80%;"></el-image>

                <p>前端是在Vue框架下搭建的，通过vue和一些原生代码对html，css，js实现管理，产生前端页面并和交互。</p>

                <p>我们引入了element UI中的元素并进行元素布局，保证实用性的同时增加了美观和用户交互，提高了用户体验 </p>

                <p>我们使用了vue-router进行路由管理，保证页面之间的联系</p>

                <p>我们使用了VCharts进行数据处理，使得数据可视化，简洁美观</p>

                <p>我们使用了axios实现后台访问后端接口，进行数据传递及计算</p>
            </div>

        </el-tab-pane>

        <el-tab-pane label="后端">
            <div style="margin-left: 30px;">
                后端
            </div>


        </el-tab-pane>

        <el-tab-pane label="计算端">
            <div style="margin-left: 30px;">
                <h2>计算端</h2>

                <h3>类图</h3>

                <h3>算法流程图</h3>

                <h3>关键数据结构</h3>

                <h3>关键接口</h3>
            </div>

        </el-tab-pane>
    </el-tabs>

</template>
