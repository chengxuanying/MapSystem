<template>
    <el-container direction='vertical'>
        <el-container>
            <el-main>
                <h2> 算法对比 </h2>
                <div class="margin_down">下图展示了数量N为自变量，时间T为因变量的算法执行时间图，探究N与T的关系：</div>
                <el-steps :space="150" :active="0" finish-status="success">
                    <el-step title="等待中"></el-step>
                    <el-step title="快速排序"></el-step>
                    <el-step title="桶排序"></el-step>
                    <el-step title="堆排序"></el-step>
                    <el-step title="插入排序"></el-step>
                    <el-step title="冒泡排序"></el-step>
                </el-steps>

            </el-main>

            <el-row>
                <el-col :span="3">
                    &nbsp;
                </el-col>

                <el-col :span="16">
                    <el-containter>
                        <ve-line :data="chartData" :settings="chartSettings"></ve-line>
                    </el-containter>
                </el-col>

                <el-col :span="4">
                    &nbsp;
                </el-col>
            </el-row>

            <el-row>
                <el-col :span="3">
                    &nbsp;
                </el-col>

                <el-col :span="16">
                    <el-col :span="11">
                        <el-button type="primary" icon="el-icon-switch-button" class="margin_down">运行全部</el-button>
                    </el-col>
                </el-col>

                <el-col :span="4">
                    &nbsp;
                </el-col>
            </el-row>


            <el-footer>
                <div class="margin_down">从如上结果中我们不难看出。。。。</div>
            </el-footer>
        </el-container>


    </el-container>

</template>

<script>

    import axios from 'axios'

    export default {
        data() {
            this.chartSettings = {
                metrics: ['冒泡排序', '插入排序'],
                yAxisName: ['T/ms'],
                xAxisName: ['N/记录数'],
                dimension: ['数据量']
            }
            return {
                chartData: {
                    columns: ['数据量', '访问用户', '下单用户'],
                    rows: []
                }
            };
        },
        created() {
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
    .el-footer {
        padding: 22px;
    }

    .margin_down {
        margin-bottom: 15px;
    }

    .margin_right {
        margin-right: 15px;
    }
</style>