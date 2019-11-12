<template>

    <el-container direction="vertical">
        <el-carousel height="450px" class="margin_down2">
            <el-carousel-item>
                <!--el-carousel-item v-for="item in photos" :key="item">
                    <h3 class="small">{{ item }}</h3>
                </el-carousel-item-->
                <el-image src="dist/IMG_5976 2.jpg" class="carousel_image_type" fit="contain"></el-image>
            </el-carousel-item>
            <el-carousel-item>
                <!--el-carousel-item v-for="item in photos" :key="item">
                    <h3 class="small">{{ item }}</h3>
                </el-carousel-item-->
                <el-image src="dist/IMG_5976 3.jpg" class="carousel_image_type" fit="fill"></el-image>
            </el-carousel-item>
 <el-carousel-item>
                <!--el-carousel-item v-for="item in photos" :key="item">
                    <h3 class="small">{{ item }}</h3>
                </el-carousel-item-->
                <el-image src="dist/IMG_5976 4.jpg" class="carousel_image_type" fit="fill"></el-image>
            </el-carousel-item>
        </el-carousel>

        <el-row type="flex" justify="space-around">
            <el-col :span="6">
                <el-card :body-style="{ padding: '0px' }" shadow="never">
                    <img src="https://shadow.elemecdn.com/app/element/hamburger.9cf7b091-55e9-11e9-a976-7f4d0b07eef6.png"
                         class="image">
                    <div style="padding: 10px; text-align: center;">
                        <span>低耦合设计</span>
                    </div>
                </el-card>
            </el-col>
            <el-col :span="6">
                <el-card :body-style="{ padding: '0px' }" shadow="never">
                    <img src="https://shadow.elemecdn.com/app/element/hamburger.9cf7b091-55e9-11e9-a976-7f4d0b07eef6.png"
                         class="image">
                    <div style="padding: 10px; text-align: center;">
                        <span>可视化界面</span>
                    </div>
                </el-card>
            </el-col>
            <el-col :span="6">
                <el-card :body-style="{ padding: '0px' }" shadow="never">
                    <img src="https://shadow.elemecdn.com/app/element/hamburger.9cf7b091-55e9-11e9-a976-7f4d0b07eef6.png"
                         class="image">
                    <div style="padding: 10px; text-align: center;">
                        <span>高可用服务</span>
                    </div>
                </el-card>
            </el-col>
        </el-row>
    </el-container>

</template>

<script>

</script>

<style>
    .margin_down2 {
        margin-bottom: 30px;
    }
</style>