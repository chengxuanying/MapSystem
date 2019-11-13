<template>
    <el-container direction='vertical'>
        <h2> 算法对比 </h2>
        <el-tabs v-model="activeName" @tab-click="handleClick">
            <el-tab-pane label="LinkID" name="linkid">
                <h3>排序关键字: LinkID</h3>

                <el-container>
                    <el-main>
                        <div class="margin_down">下图展示了数量N为自变量，时间T为因变量的算法执行时间图，探究N与T的关系：</div>
                        <el-steps :space="100" :active="myactive[1]" finish-status="success">
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
                            <!--                            <el-containter>-->
                            <ve-line :data="chartData1" :settings="chartSettings" ref="chart1"></ve-line>
                            <!--                            </el-containter>-->
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


            </el-tab-pane>

            <el-tab-pane label="道路名称" name="name">
                <h3> 排序关键字: 道路名称</h3>
                <el-container>
                    <el-main>
                        <div class="margin_down">下图展示了数量N为自变量，时间T为因变量的算法执行时间图，探究N与T的关系：</div>
                        <el-steps :space="100" :active="myactive[2]" finish-status="success">
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
                                <ve-line :data="chartData2" :settings="chartSettings" ref="chart2"></ve-line>
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
                                           @click="get_name"
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
            </el-tab-pane>

            <el-tab-pane label="岔路数量" name="chalu">
                <h3>排序关键字: 岔路数量</h3>
                <el-container>
                    <el-main>
                        <div class="margin_down">下图展示了数量N为自变量，时间T为因变量的算法执行时间图，探究N与T的关系：</div>
                        <el-steps :space="100" :active="myactive[3]" finish-status="success">
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
                                <ve-line :data="chartData3" :settings="chartSettings" ref="chart3"></ve-line>
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
                                           @click="get_chalu"
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
            </el-tab-pane>

            <el-tab-pane label="道路番号" name="fanhao">
                <h3> 排序关键字: 道路番号</h3>
                <el-container>
                    <el-main>
                        <div class="margin_down">下图展示了数量N为自变量，时间T为因变量的算法执行时间图，探究N与T的关系：</div>
                        <el-steps :space="100" :active="myactive[4]" finish-status="success">
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
                                <ve-line :data="chartData4" :settings="chartSettings" ref="chart4"></ve-line>
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
                                           @click="get_fanhao"
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

            </el-tab-pane>
        </el-tabs>
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
                chartData1: {
                    columns: ['n', 'our', 'stdsort', 'qsort', 'bucketsort', 'heapsort', 'insertsort', 'bubblesort'],
                    rows: [{'n': '0', 'our': 0}]
                },
                chartData2: {
                    columns: ['n', 'our', 'stdsort', 'qsort', 'bucketsort', 'heapsort', 'insertsort', 'bubblesort'],
                    rows: [{'n': '0', 'our': 0}]
                },
                chartData3: {
                    columns: ['n', 'our', 'stdsort', 'qsort', 'bucketsort', 'heapsort', 'insertsort', 'bubblesort'],
                    rows: [{'n': '0', 'our': 0}]
                },
                chartData4: {
                    columns: ['n', 'our', 'stdsort', 'qsort', 'bucketsort', 'heapsort', 'insertsort', 'bubblesort'],
                    rows: [{'n': '0', 'our': 0}]
                },
                myactive:[0,0,0,0,0],
                linkid_load: false,
                activeName: 'linkid'
            };
        },
        methods: {
            get_linkid() {
                var self = this;
                self.$set(self.myactive, 1, 0);
                var url = `http://127.0.0.1:5000/sort/linkid`;
                axios.get(url).then(function (res) {
                    self.linkid_load = true;
                    self.next_point(12 * 7, self.chartData1, 1);
                }).catch(function (error) {
                    console.log(error);
                });
            },
            get_name() {
                var self = this;
                self.$set(self.myactive, 2, 0);
                var url = `http://127.0.0.1:5000/sort/name`;
                axios.get(url).then(function (res) {
                    self.linkid_load = true;
                    self.next_point(12 * 7, self.chartData2, 2);
                }).catch(function (error) {
                    console.log(error);
                });
            },
            get_chalu() {
                var self = this;
                self.$set(self.myactive, 3, 0);
                var url = `http://127.0.0.1:5000/sort/chalu`;
                axios.get(url).then(function (res) {
                    self.linkid_load = true;
                    self.next_point(12 * 7, self.chartData3, 3);
                }).catch(function (error) {
                    console.log(error);
                });
            },
            get_fanhao() {
                var self = this;
                self.$set(self.myactive, 4, 0);
                var url = `http://127.0.0.1:5000/sort/fanhao`;
                axios.get(url).then(function (res) {
                    self.linkid_load = true;
                    self.next_point(12 * 7, self.chartData4, 4);
                }).catch(function (error) {
                    console.log(error);
                });
            },
            next_point(n, chart_, active) {
                var self = this;
                if (n === 0) {
                    self.$set(self.myactive, active, self.myactive[active]+1);
                    self.linkid_load = false;
                    return;
                }
                var url = `http://127.0.0.1:5000/sort/next`;
                axios.get(url).then(function (res) {
                    // console.log(res.data.result);
                    chart_.rows = res.data.result;
                    if (n % 12 === 0) {
                       self.$set(self.myactive, active, self.myactive[active]+1);
                    }
                    self.next_point(n - 1, chart_, active);
                }).catch(function (error) {
                    console.log(error);
                });
            },
            handleClick(tab, event) {
                var self = this;
                console.log(tab, event);
            },
        },
        watch: {
            activeName(v) {
                this.$nextTick(_ => {
                    this.$refs[`chart1`].echarts.resize();
                    this.$refs[`chart2`].echarts.resize();
                    this.$refs[`chart3`].echarts.resize();
                    this.$refs[`chart4`].echarts.resize();
                })
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