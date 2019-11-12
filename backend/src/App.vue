<template>    <!--模-->
    <div id="app">


        <!--        <el-container>-->


        <!--                        <div class="grid-content bg-purple"></div>-->
        <el-row :gutter="20">
            <el-col :span="4">
                <div class="grid-content bg-purple"></div>
            </el-col>
            <el-col :span="16">
                <el-container>
                    <el-header>
                        <el-menu :default-active="activeIndex" class="el-menu-demo" mode="horizontal"
                                 @select="handleSelect">
                            <el-menu-item index="1"><i class="el-icon-place"></i>Mapsystem</el-menu-item>
                            <el-menu-item index="3">数据分析</el-menu-item>
                            <el-menu-item index="4">排序算法分析</el-menu-item>
                            <el-menu-item index="5">项目文档</el-menu-item>
                        </el-menu>
                    </el-header>


                    <el-carousel height="190px">
                        <el-carousel-item v-for="item in 4" :key="item">
                            <h3 class="small">{{ item }}</h3>
                        </el-carousel-item>
                    </el-carousel>


                    <el-footer>
                        <el-divider></el-divider>
                        <el-alert
                                title="Made with love by 3 boys."
                                type="info"
                                close-text=" ">
                        </el-alert>
                   </el-footer>

                </el-container>
            </el-col>
            <el-col :span="4">
                <div class="grid-content bg-purple"></div>
            </el-col>


        </el-row>


        <!--        </el-container>-->

        <!--        <el-container>-->
        <!--            <el-header>-->
        <!--                <el-menu :default-active="activeIndex" class="el-menu-demo" mode="horizontal" @select="handleSelect">-->
        <!--                    <el-menu-item index="1">处理中心</el-menu-item>-->
        <!--                    <el-submenu index="2">-->
        <!--                        <template slot="title">我的工作台</template>-->
        <!--                        <el-menu-item index="2-1">选项1</el-menu-item>-->
        <!--                        <el-menu-item index="2-2">选项2</el-menu-item>-->
        <!--                        <el-menu-item index="2-3">选项3</el-menu-item>-->
        <!--                        <el-submenu index="2-4">-->
        <!--                            <template slot="title">选项4</template>-->
        <!--                            <el-menu-item index="2-4-1">选项1</el-menu-item>-->
        <!--                            <el-menu-item index="2-4-2">选项2</el-menu-item>-->
        <!--                            <el-menu-item index="2-4-3">选项3</el-menu-item>-->
        <!--                        </el-submenu>-->
        <!--                    </el-submenu>-->
        <!--                    <el-menu-item index="3">消息中心</el-menu-item>-->
        <!--                    <el-menu-item index="4"><a href="https://www.ele.me" target="_blank">订单管理</a></el-menu-item>-->
        <!--                </el-menu>-->
        <!--                <div class="line"></div>-->
        <!--            </el-header>-->

        <!--        </el-container>-->

        <!--        <el-container>-->
        <!--            <el-header>-->
        <!--                <el-menu :default-active="activeIndex" class="el-menu-demo" mode="horizontal" @select="handleSelect">-->
        <!--                    <el-menu-item index="1">处理中心</el-menu-item>-->
        <!--                    <el-submenu index="2">-->
        <!--                        <template slot="title">我的工作台</template>-->
        <!--                        <el-menu-item index="2-1">选项1</el-menu-item>-->
        <!--                        <el-menu-item index="2-2">选项2</el-menu-item>-->
        <!--                        <el-menu-item index="2-3">选项3</el-menu-item>-->
        <!--                        <el-submenu index="2-4">-->
        <!--                            <template slot="title">选项4</template>-->
        <!--                            <el-menu-item index="2-4-1">选项1</el-menu-item>-->
        <!--                            <el-menu-item index="2-4-2">选项2</el-menu-item>-->
        <!--                            <el-menu-item index="2-4-3">选项3</el-menu-item>-->
        <!--                        </el-submenu>-->
        <!--                    </el-submenu>-->
        <!--                    <el-menu-item index="3">消息中心</el-menu-item>-->
        <!--                    <el-menu-item index="4"><a href="https://www.ele.me" target="_blank">订单管理</a></el-menu-item>-->
        <!--                </el-menu>-->
        <!--                <div class="line"></div>-->
        <!--            </el-header>-->


        <!--        </el-container>-->


    </div>

</template>

<script>
    export default {
        methods: {
            startHacking() {
                this.$notify({
                    title: 'It works!',
                    type: 'success',
                    message: 'We\'ve laid the ground work for you. It\'s time for you to build something epic!',
                    duration: 5000
                })
            }
        }
    }
</script>

<style>
    #app {
        font-family: Helvetica, sans-serif;
        text-align: center;
    }

    .el-aside {
        background-color: #D3DCE6;
        color: #333;
        text-align: center;
        line-height: 200px;
    }


    .el-main {
        background-color: #E9EEF3;
        color: #333;
        text-align: center;
        line-height: 200px;
    }

    body > .el-container {
        margin-bottom: 80px;
    }

    .el-carousel__item h3 {
        color: #475669;
        font-size: 18px;
        opacity: 0.75;
        line-height: 300px;
        margin: 0;
    }

    .el-carousel__item:nth-child(2n) {
        background-color: #99a9bf;
    }

    .el-carousel__item:nth-child(2n+1) {
        background-color: #d3dce6;
    }

    .el-carousel__item h3 {
        color: #475669;
        font-size: 14px;
        opacity: 0.75;
        line-height: 150px;
        margin: 0;
    }

    .el-carousel__item:nth-child(2n) {
        background-color: #99a9bf;
    }

    .el-carousel__item:nth-child(2n+1) {
        background-color: #d3dce6;
    }

    .el-col {
        border-radius: 4px;
    }


    .bg-purple {
        /*background: #d3dce6;*/
    }


    .grid-content {
        border-radius: 4px;
        min-height: 36px;
    }

    .row-bg {
        padding: 10px 0;
        background-color: #f9fafc;
    }
</style>

