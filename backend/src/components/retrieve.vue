<template>
<el-container>
  <el-table
    :data="tableData"
    style="width: 100%">
    <el-table-column
      prop="linkid"
      label="LinkID">
    </el-table-column>
      <el-table-column
        prop="name"
        label="道路名称">
      </el-table-column>
      <el-table-column label="情报">
        <el-table-column
          prop="chalu"
          label="岔路数量">
        </el-table-column>
        <el-table-column
          prop="fanhao"
          label="道路番号">
        </el-table-column>
        <el-table-column
          prop="flag"
          label="Flag">
        </el-table-column>
      </el-table-column>
  </el-table>
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
    created(){
        axios.get('http://127.0.0.1:5000/retrieve/test',{       // 还可以直接把参数拼接在url后边
        }).then(function(res){
            //console.log(res.data.result);
            this.tableData = res.data.result;
                //   console.log(this.tableData);
            // var obj = JSON.parse(res.data);
        //console.log(this.tableData);
        }).catch(function (error) {
            console.log(error);
        });
  
}
  }
</script>
<style>
</style>
