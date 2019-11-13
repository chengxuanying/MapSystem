<template>
    <el-container direction='vertical'>
        <el-container>
            <el-main>
                <h2> 算法对比 </h2>
                <h3> 排序关键字: LinkID </h3>
                <div class="margin_down">下图展示了数量N为自变量，时间T为因变量的算法执行时间图，探究N与T的关系：</div>
                <el-steps :space="100" :active="myactive" finish-status="success">
                    <el-step title="等待评测"></el-step>
                    <el-step title="改进方法1"></el-step>
                    <el-step title="STD排序"></el-step>
                    <el-step title="快速排序"></el-step>
                    <el-step title="桶排序"></el-step>
                    <el-step title="堆排序"></el-step>
                    <el-step title="插入排序"></el-step>
                    <el-step title="冒泡排序"></el-step>

                </el-steps>

            </el-main>

            <el-row>
                <el-col :span="2">
                    &nbsp;
                </el-col>

                <el-col :span="18">
                    <el-containter>
                        <ve-line :data="chartData" :settings="chartSettings"></ve-line>

                    </el-containter>
                </el-col>

                <el-col :span="1">
                    &nbsp;
                </el-col>
            </el-row>

            <el-row>
                <el-col :span="3">
                    &nbsp;
                </el-col>

                <el-col :span="16">
                    <el-col :span="11">
                        <el-button type="primary"
                                   icon="el-icon-switch-button"
                                   class="margin_down"
                                   @click="get_linkid"
                                   :loading="linkid_load">
                            评测排序算法
                        </el-button>
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
                metrics: ['our', 'stdsort', 'qsort', 'bucketsort', 'heapsort', 'insertsort', 'bubblesort'],
                yAxisName: ['T/us'],
                xAxisName: ['N/数据量'],
                xAxisType: ['value'],
                dimension: ['n']
            }
            return {
                chartData: {
                    columns: ['n', 'our', 'stdsort', 'qsort', 'bucketsort', 'heapsort', 'insertsort', 'bubblesort'],
                    rows: [{'n': '0', 'our': 0}]
                },
                myactive: 0,
                linkid_load: false,
            };
        },
        methods: {
            get_linkid() {
                var self = this;
                self.myactive = 0;

                var url = `http://127.0.0.1:5000/sort/linkid`;

                axios.get(url).then(function (res) {
                    self.linkid_load = true;
                    self.next_point(12 * 7);
                }).catch(function (error) {
                    console.log(error);
                });


            },
            next_point(n) {
                var self = this;

                // console.log(n)
                if (n === 0) {
                    self.myactive += 1;
                    self.linkid_load = false;
                    return;
                }


                var url = `http://127.0.0.1:5000/sort/next`;

                axios.get(url).then(function (res) {
                    // console.log(res.data.result);
                    self.chartData.rows = res.data.result;
                    if (n % 12 === 0) {
                        self.myactive += 1;
                    }

                    self.next_point(n - 1);


                }).catch(function (error) {
                    console.log(error);
                });
            }
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