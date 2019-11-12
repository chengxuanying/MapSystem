<template>
    <el-container direction='vertical'>
        <el-container>
            <el-main>
                <h2>这里是标题： </h2>
                <h3>这里是描述1： </h3>
            </el-main>
            <el-containter>
                <ve-line :data="chartData" :settings="chartSettings"></ve-line>
            </el-containter>
            <el-footer>
                <h3>这里是描述2: </h3>
            </el-footer>
        </el-container>
        <el-container>
            <el-main>
                <el-divider></el-divider>
                <h2>这里是标题： </h2>
                <h3>这里是描述1： </h3>
            </el-main>
            <el-containter>
                <ve-line :data="chartData" :settings="chartSettings"></ve-line>
            </el-containter>
            <el-footer>
                <h3>这里是描述2: </h3>
            </el-footer>
        </el-container>
        <el-container>
            <el-main>
                <el-divider></el-divider>
                <h2>这里是标题： </h2>
                <h3>这里是描述1： </h3>
            </el-main>
            <el-containter>
                <ve-line :data="chartData" :settings="chartSettings"></ve-line>
            </el-containter>
            <el-footer>
                <h3>这里是描述2: </h3>
            </el-footer>
        </el-container>
        <el-container>
            <el-main>
                <el-divider></el-divider>
                <h2>这里是标题： </h2>
                <h3>这里是描述1： </h3>
            </el-main>
            <el-containter>
                <ve-line :data="chartData" :settings="chartSettings"></ve-line>
            </el-containter>
            <el-footer>
                <h3>这里是描述2: </h3>
            </el-footer>
        </el-container>
        <el-container>
            <el-main>
                <el-divider></el-divider>
                <h2>这里是标题： </h2>
                <h3>这里是描述1： </h3>
            </el-main>
            <el-containter>
                <ve-line :data="chartData" :settings="chartSettings"></ve-line>
            </el-containter>
            <el-footer>
                <h3>这里是描述2: </h3>
            </el-footer>
        </el-container>
    </el-container>
  
</template>

<script>

import axios from 'axios'
export default {
    data () {
        this.chartSettings = {
        metrics: ['访问用户', '下单用户'],
        dimension: ['数据量']
        }
        return {
        chartData: {
            columns: ['数据量', '访问用户', '下单用户'],
            rows: []
        }
        };
    },
    created(){
    var self = this;
        var url = `http://127.0.0.1:5000/sort`;

        axios.get(url).then(function (res) {
            self.chartData.rows = res.data.result;
            //console.log(res.data);
            //console.log(self.chartData.rows);
        }).catch(function (error) {
            console.log(error);
        });
    }
}
</script>
<style>
.el-footer{
    padding:22px;
}
</style>