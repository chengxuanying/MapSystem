<template>
    <el-container direction="vertical">
        <el-table
                :data="tableData"
                style="width: 100%">
            <el-table-column
                    prop="linkid"
                    label="LinkID"
                    width="80">
            </el-table-column>
            <el-table-column
                    prop="name"
                    label="道路名称">
            </el-table-column>
            <el-table-column label="情报">
                <el-table-column
                        prop="chalu"
                        label="岔路数量"
                        width="80">
                </el-table-column>
                <el-table-column
                        prop="fanhao"
                        label="道路番号"
                        width="80">
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
                class="nav-margin">
        </el-pagination>

    </el-container>
</template>

<script>

    import axios from 'axios'

    export default {
        data() {
            return {
                tableData: []
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


            axios.get('http://127.0.0.1:5000/retrieve/tot', {
            }).then(function (res) {
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

              axios.get(url, {
              }).then(function (res) {
                  self.tableData = res.data.result;
              }).catch(function (error) {
                  console.log(error);
              });
            }
        }
    }
</script>
<style>
    .nav-margin {
        margin-top: 35px;
    }
</style>
