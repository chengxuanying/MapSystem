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
                :page-sizes="[100, 200, 300, 400]"
                :page-size="100"
                layout="total, sizes, prev, pager, next, jumper"
                :total="400"
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
            axios.get('http://127.0.0.1:5000/retrieve/test', {       // 还可以直接把参数拼接在url后边
            }).then(function (res) {
                self.tableData = res.data.result;
            }).catch(function (error) {
                console.log(error);
            });

        }
    }
</script>
<style>
    .nav-margin {
        margin-top: 35px;
    }
</style>
