<template>
    <el-container direction="vertical">
        <el-row>
            <el-col :span="11">
                <h2>数据检索</h2>
            </el-col>


            <el-col :span="13">
                <el-badge :value="count" class="item">
                    <el-input placeholder="请输入内容" v-model="input3" class="input-with-select search-margin">
                        <el-select v-model="select" slot="prepend" placeholder="请选择">
                            <el-option label="LinkID" value="linkid"></el-option>
                            <el-option label="道路名称" value="name"></el-option>
                            <el-option label="岔路数量" value="chalu"></el-option>
                            <el-option label="道路番号" value="fanhao"></el-option>
                        </el-select>
                        <el-button slot="append" icon="el-icon-search" @click="search"></el-button>
                        <el-button slot="append" @click="nosearch">取消搜索</el-button>
                    </el-input>
                </el-badge>
            </el-col>
        </el-row>


        <el-table
                :data="tableData"
                style="width: 100%"
                @sort-change="my_sort">
            <el-table-column
                    prop="linkid"
                    label="LinkID"
                    width="110"
                    sortable="custom">
            </el-table-column>
            <el-table-column
                    prop="name"
                    label="道路名称"
                    sortable="custom">
            </el-table-column>
            <el-table-column label="情报">
                <el-table-column
                        prop="chalu"
                        label="岔路数量"
                        width="110"
                        sortable="custom">
                </el-table-column>
                <el-table-column
                        prop="fanhao"
                        label="道路番号"
                        width="110"
                        sortable="custom">
                </el-table-column>
                <el-table-column
                        prop="flag"
                        label="Flag"
                        width="80">
                </el-table-column>
            </el-table-column>
        </el-table>
        <el-pagination
                @size-change="handleSizeChange"
                @current-change="handleCurrentChange"
                :current-page="currentPage4"
                :page-size="15"
                :page-sizes="[10, 15, 20, 30, 40]"
                layout="total, sizes, prev, pager, next, jumper"
                :total="total"
                class="nav-margin"
                v-if="seen">
        </el-pagination>

    </el-container>
</template>

<script>

    import axios from 'axios';
    import {Loading} from 'element-ui';

    export default {
        data() {
            return {
                tableData: [],
                fullscreenLoading: false,
                input3: '',
                select: '',
                seen: true,
                count: 0,
            }
        },
        created() {
            var self = this;


            // axios.get('http://127.0.0.1:5000/retrieve/test', {
            // }).then(function (res) {
            //     self.tableData = res.data.result;
            // }).catch(function (error) {
            //     console.log(error);
            // });


            axios.get('http://127.0.0.1:5000/retrieve/tot', {}).then(function (res) {
                self.total = res.data.tot;
                console.log(self.total);
            }).catch(function (error) {
                console.log(error);
            });

            this.page_size = 15;
            this.cur_page = 1;


            self.handleCurrentChange(1);

        }, methods: {
            handleSizeChange(val) {
                this.page_size = val;
                this.handleCurrentChange(this.cur_page);

            },
            handleCurrentChange(val) {
                console.log(123218)
                this.cur_page = val;

                var self = this;
                var page_size = self.page_size;
                var url = `http://127.0.0.1:5000/retrieve/page_size/${page_size}/page/${val}`;

                axios.get(url, {}).then(function (res) {
                    self.tableData = res.data.result;
                    //console.log(res.data);
                    self.count = res.data.tot;
                }).catch(function (error) {
                    console.log(error);
                });
            }, openFullScreen() {
                this.fullscreenLoading = true;
                setTimeout(() => {
                    this.fullscreenLoading = false;
                }, 2000);
            },
            my_sort(row, column) {
                var lie = row.prop;
                var shunxu = row.order;

                var self = this;
                let loadingInstance = Loading.service({fullscreen: true});

                var url = `http://127.0.0.1:5000/retrieve/sort/${lie}/${shunxu}`;

                axios.get(url, {}).then(function (res) {
                    self.handleCurrentChange(1);
                    loadingInstance.close();


                }).catch(function (error) {
                    console.log(error);
                });

                this.openFullScreen();


            },
            search() {
                var self = this;

                var arg1 = this.select;
                var arg2 = this.input3;

                var url = `http://127.0.0.1:5000/retrieve/${arg1}/${arg2}`;

                axios.get(url, {}).then(function (res) {
                    self.tableData = res.data.result;
                    self.count = res.data.cnt;
                    // console.log(res.data);
                    if (self.count === 0) {
                        self.$message({
                            message: '没有检索到数据！',
                            type: 'error',
                            duration: 5000,
                        });
                    } else {
                        self.$message({
                            message: `成功检索到${self.count}条数据！`,
                            type: 'success',
                            duration: 5000,
                        });
                    }

                }).catch(function (error) {
                    console.log(error);
                });

                self.seen = false;
            },
            nosearch() {
                var self = this;

                self.seen = true;
                self.handleCurrentChange(1);
            }
        }
    }
</script>
<style>
    .nav-margin {
        margin-top: 35px;
    }

    .search-margin {
        margin-bottom: 15px;
    }

    .el-select .el-input {
        width: 130px;
    }

    .input-with-select .el-input-group__prepend {
        background-color: #fff;
    }

    .item {
        margin-top: 10px;
        margin-right: 40px;
    }
</style>
