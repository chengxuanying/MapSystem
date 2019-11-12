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
 export default {
    data() {
      return {
        tableData: [{"chalu":3,"fanhao":6,"flag":1,"linkid":2130,"name":"１＝104国道"},{"chalu":2,"fanhao":4,"flag":0,"linkid":2131,"name":""},{"chalu":2,"fanhao":6,"flag":1,"linkid":2132,"name":"１＝104国道"},{"chalu":3,"fanhao":11,"flag":0,"linkid":11852,"name":""},{"chalu":3,"fanhao":11,"flag":0,"linkid":12391,"name":""},{"chalu":3,"fanhao":6,"flag":1,"linkid":2133,"name":"１＝104国道"},{"chalu":2,"fanhao":6,"flag":1,"linkid":2134,"name":"１＝104国道"},{"chalu":2,"fanhao":11,"flag":0,"linkid":11835,"name":""},{"chalu":2,"fanhao":4,"flag":1,"linkid":811,"name":"１＝杭宁高速公路"},{"chalu":1,"fanhao":4,"flag":1,"linkid":846,"name":"１＝杭宁高速公路"}]
      }
    }
  }
</script>
<style>
</style>
