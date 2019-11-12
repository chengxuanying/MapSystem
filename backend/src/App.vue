<template>
  <div id="app">
    <el-row :gutter="20">
            <el-col :span="4">
                <div class="grid-content bg-purple"></div>
            </el-col>
            <el-col :span="16">
                <el-container>
                    <el-header>
                        <el-menu :default-active="activeIndex" class="el-menu-demo" mode="horizontal" router>
                            <el-menu-item index="/home"><i class="el-icon-place"></i>Mapsystem</el-menu-item>
                            <el-menu-item index="/retrieve">数据分析</el-menu-item>
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
                                close-text=" ">
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
  text-align: center;
  color: #2c3e50;
  margin-top: 30px;
}

.margin{
  margin-top: 60px;
}
</style>
