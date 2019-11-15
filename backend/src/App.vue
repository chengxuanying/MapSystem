<template>
    <div id="app" class="bkg">
        <el-row :gutter="20" >
            <el-col :span="4">
                <div class="grid-content bg-purple"></div>
            </el-col>
            <el-col :span="16">
                <el-container>
                    <el-header>
                        <el-menu :default-active="activeIndex" class="el-menu-demo" mode="horizontal" router>
                            <el-menu-item index="/home"><i class="el-icon-place"></i>Mapsystem</el-menu-item>
                            <el-menu-item index="/retrieve">数据检索</el-menu-item>
                            <el-menu-item index="/sort">排序算法分析</el-menu-item>
                            <el-menu-item index="/docs">项目文档</el-menu-item>
                        </el-menu>
                    </el-header>

                    <div class="margin"></div>

                    <router-view></router-view>
                    <el-footer>
                        <el-divider></el-divider>
                        <el-alert
                                title="Made with love by 3 boys."
                                type="info"
                                close-text=" "
                                class="footer-margin">
                        </el-alert>
                    </el-footer>

                </el-container>
            </el-col>
            <el-col :span="4">
                <div class="grid-content bg-purple"></div>
            </el-col>
        </el-row>
    </div>
</template>

<script>
    export default {
        data(){
            return {
                activeIndex:this.$route.path
            }
        }
    }
</script>

<style>

    .grid-content {
        border-radius: 4px;
        min-height: 36px;
    }

    .bg-purple {
        /*background: #d3dce6;*/
    }

    #app {
        font-family: 'Avenir', Helvetica, Arial, sans-serif;
        -webkit-font-smoothing: antialiased;
        -moz-osx-font-smoothing: grayscale;
        /*text-align: center;*/
        color: #2c3e50;
        margin-top: 30px;
    }

    .margin {
        margin-top: 23px;
    }

    .el-header {
        padding: 0px;
    }

    .el-footer {
        padding: 0px;
    }

    .footer-margin {
        margin-bottom: 100px;
    }

    .bkg{
        /*background:url("../assets/bkg-min.jpg") no-repeat;*/
        /*background-size:contain;*/
        /*width:10rem;*/
        /*height:5rem;*/
    }
</style>
