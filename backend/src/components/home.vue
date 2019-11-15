<template>

    <el-container direction="vertical">
        <el-carousel class="margin_down2">
            <el-carousel-item>
                <!--el-carousel-item v-for="item in photos" :key="item">
                    <h3 class="small">{{ item }}</h3>
                </el-carousel-item-->
                <el-image src="../assets/17.jpg" class="carousel_image_type" fit="contain"></el-image>
            </el-carousel-item>
            <el-carousel-item>
                <!--el-carousel-item v-for="item in photos" :key="item">
                    <h3 class="small">{{ item }}</h3>
                </el-carousel-item-->
                <el-image src="../assets/16.jpg" class="carousel_image_type" fit="contain"></el-image>
            </el-carousel-item>
            <el-carousel-item>
                <!--el-carousel-item v-for="item in photos" :key="item">
                    <h3 class="small">{{ item }}</h3>
                </el-carousel-item-->
                <el-image src="../assets/15.jpg" class="carousel_image_type" fit="contain"></el-image>
            </el-carousel-item>
            <el-carousel-item>
                <!--el-carousel-item v-for="item in photos" :key="item">
                    <h3 class="small">{{ item }}</h3>
                </el-carousel-item-->
                <el-image src="../assets/22-min.jpg" class="carousel_image_type" fit="contain"></el-image>
            </el-carousel-item>
            <el-carousel-item>
                <!--el-carousel-item v-for="item in photos" :key="item">
                    <h3 class="small">{{ item }}</h3>
                </el-carousel-item-->
                <el-image src="../assets/21-min.jpg" class="carousel_image_type" fit="contain"></el-image>
            </el-carousel-item>
            <el-carousel-item>
                <!--el-carousel-item v-for="item in photos" :key="item">
                    <h3 class="small">{{ item }}</h3>
                </el-carousel-item-->
                <el-image src="../assets/23-min.jpg" class="carousel_image_type" fit="contain"></el-image>
            </el-carousel-item>
        </el-carousel>

        <el-row type="flex" justify="space-around">
            <el-col :span="6">
                <el-card :body-style="{ padding: '5px' }">
                    <img src="assets/8.png"
                         class="image">
                    <div style="padding: 18px; text-align: center;">
                        <span>低耦合设计</span>
                    </div>
                </el-card>
            </el-col>
            <el-col :span="6">
                <el-card :body-style="{ padding: '1px' }">
                    <img src="assets/9.png"
                         class="image">
                    <div style="padding: 22px; text-align: center;">
                        <span>可视化设计</span>
                    </div>
                </el-card>
            </el-col>
            <el-col :span="6">
                <el-card :body-style="{ padding: '2px' }">
                    <img src="assets/10.png"
                         class="image">
                    <div style="padding: 20px; text-align: center;">
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

    .image {
        width: auto;
        height: auto;
        max-width: 100%;
        max-height: 100%;
    }
</style>