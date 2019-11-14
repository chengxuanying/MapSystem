<template>
    <el-container direction='vertical'>

        <h2> 算法对比 </h2>
        <el-tabs v-model="activeName" @tab-click="handleClick">
            <el-tab-pane label="LinkID" name="linkid">
                <h3>排序关键字: LinkID</h3>

                <el-container direction="vertical">
                    <el-main>
                        <div class="margin_down">下图展示了数量N为自变量，时间T为因变量的算法执行时间图，探究N与T的关系：</div>
                        <el-steps :space="100" :active="myactive[1]" finish-status="success">
                            <el-step title="等待评测"></el-step>
                            <el-step title="改进方法1"></el-step>
                            <el-step title="桶排序"></el-step>
                            <el-step title="STD排序"></el-step>
                            <el-step title="堆排序"></el-step>
                            <el-step title="快速排序"></el-step>
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
                </el-container>


            </el-tab-pane>

            <el-tab-pane label="道路名称" name="name">
                <h3> 排序关键字: 道路名称</h3>
                <el-container direction="vertical">
                    <el-main>
                        <div class="margin_down">下图展示了数量N为自变量，时间T为因变量的算法执行时间图，探究N与T的关系：</div>
                        <el-steps :space="100" :active="myactive[2]" finish-status="success">
                            <el-step title="等待评测"></el-step>
                            <el-step title="改进方法1"></el-step>
                            <el-step title="桶排序"></el-step>
                            <el-step title="STD排序"></el-step>
                            <el-step title="堆排序"></el-step>
                            <el-step title="快速排序"></el-step>
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
                </el-container>
            </el-tab-pane>

            <el-tab-pane label="岔路数量" name="chalu">
                <h3>排序关键字: 岔路数量</h3>
                <el-container direction="vertical">
                    <el-main>
                        <div class="margin_down">下图展示了数量N为自变量，时间T为因变量的算法执行时间图，探究N与T的关系：</div>
                        <el-steps :space="100" :active="myactive[3]" finish-status="success">
                            <el-step title="等待评测"></el-step>
                            <el-step title="改进方法1"></el-step>
                            <el-step title="桶排序"></el-step>
                            <el-step title="STD排序"></el-step>
                            <el-step title="堆排序"></el-step>
                            <el-step title="快速排序"></el-step>
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
                </el-container>
            </el-tab-pane>

            <el-tab-pane label="道路番号" name="fanhao">
                <h3> 排序关键字: 道路番号</h3>
                <el-container direction="vertical">
                    <el-main>
                        <div class="margin_down">下图展示了数量N为自变量，时间T为因变量的算法执行时间图，探究N与T的关系：</div>
                        <el-steps :space="100" :active="myactive[4]" finish-status="success">
                            <el-step title="等待评测"></el-step>
                            <el-step title="改进方法1"></el-step>
                            <el-step title="桶排序"></el-step>
                            <el-step title="STD排序"></el-step>
                            <el-step title="堆排序"></el-step>
                            <el-step title="快速排序"></el-step>
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
                </el-container>
            </el-tab-pane>
        </el-tabs>
        <el-row>
            <el-col :span="2">&nbsp;</el-col>
            <el-col :span="20">
                <p>点击评测排序算法按钮开始评测。</p>
                <el-row>&nbsp</el-row>
                <el-divider></el-divider>
                <h3>各算法时间复杂度与空间复杂度如下表所示:</h3>
                <el-table :data="tableData" border style="width: 100%">
                    <el-table-column prop="sort" label="算法"></el-table-column>
                    <el-table-column prop="time" label="时间复杂度"></el-table-column>
                    <el-table-column prop="address" label="空间复杂度"></el-table-column>
                </el-table>
                <el-row>&nbsp</el-row>
                <div>
                    <div>通过数据量和时间折线图我们可以看出，随着数据量的增加，时间复杂度为<katex-element expression="\log{}n"/>
                    的算法包括标准排序，快速排序，堆排序，他们的运行时间随时间变化不大。</div>
                    <p>特别值得注意的是桶排序。执行时间随数据量的成常数变化。</p>
                    <div>最后是复杂度是<katex-element expression="n^2"/>的插入排序和冒泡排序。他们的执行时间随数据量的变化较大，在图中可以看出来呈抛物线形状。</div>
                </div>
            </el-col>
            <el-col :span="2">&nbsp;</el-col>
        </el-row>
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
                activeName: 'linkid',
                tableData: [{
                    sort: '改进方法',
                    time: <div v-katex="\mathcal{0}(n\log{}n)"></div>,
                    address: <div v-katex="\mathcal{0}(n\log{}n)"></div>
                    }, {
                    sort: 'STD排序',
                    time: <div v-katex="\mathcal{0}(n\log{}n)"></div>,
                    address: <div v-katex="\mathcal{0}(n\log{}n)"></div>
                    }, {
                    sort: '快速排序',
                    time: <div v-katex="\mathcal{0}(n\log{}n)"></div>,
                    address: <div v-katex="\mathcal{0}(n\log{}n)"></div>
                    }, {
                    sort: '桶排序（桶数为m）',
                    time: <div v-katex="\mathcal{0}(n+n*(\log{}n-\log{}m))"></div>,
                    address: <div v-katex="\mathcal{0}(n+m)"></div>
                    },{
                    sort: '堆排序',
                    time: <div v-katex="\mathcal{0}(n\log{}n)"></div>,
                    address: <div v-katex="\mathcal{0}(1)"></div>
                    }, {
                    sort: '插入排序',
                    time: <div v-katex="\mathcal{0}(n^2)"></div>,
                    address: <div v-katex="\mathcal{0}(1)"></div>
                    }, {
                    sort: '冒泡排序',
                    time: <div v-katex="\mathcal{0}(n^2)"></div>,
                    address: <div v-katex="\mathcal{0}(1)"></div>
                }]
            };
        },
        methods: {
            get_linkid() {
                var self = this;
                self.$set(self.myactive, 1, 0);
                var url = `api/sort/linkid`;
                axios.get(url).then(function (res) {
                    self.linkid_load = true;
                    self.next_point(16 * 7, self.chartData1, 1);
                }).catch(function (error) {
                    console.log(error);
                });
            },
            get_name() {
                var self = this;
                self.$set(self.myactive, 2, 0);
                var url = `api/sort/name`;
                axios.get(url).then(function (res) {
                    self.linkid_load = true;
                    self.next_point(16 * 7, self.chartData2, 2);
                }).catch(function (error) {
                    console.log(error);
                });
            },
            get_chalu() {
                var self = this;
                self.$set(self.myactive, 3, 0);
                var url = `api/sort/chalu`;
                axios.get(url).then(function (res) {
                    self.linkid_load = true;
                    self.next_point(16 * 7, self.chartData3, 3);
                }).catch(function (error) {
                    console.log(error);
                });
            },
            get_fanhao() {
                var self = this;
                self.$set(self.myactive, 4, 0);
                var url = `api/sort/fanhao`;
                axios.get(url).then(function (res) {
                    self.linkid_load = true;
                    self.next_point(16 * 7, self.chartData4, 4);
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
                var url = `api/sort/next`;
                axios.get(url).then(function (res) {
                    // console.log(res.data.result);
                    chart_.rows = res.data.result;
                    if (n % 16 === 0) {
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