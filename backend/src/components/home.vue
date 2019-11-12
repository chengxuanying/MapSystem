<template>

  <el-carousel height="190px">
      <el-carousel-item v-for="item in 4" :key="item">
          <h3 class="small">{{ item }}</h3>
      </el-carousel-item>
  </el-carousel>

</template>
