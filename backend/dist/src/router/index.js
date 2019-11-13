import Vue from 'vue'
import Router from "vue-router";
import Home from '../components/home.vue'
import Retrieve from '../components/retrieve.vue'
import Sort from '../components/sort.vue'
import Docs from '../components/docs.vue'


Vue.use(Router);

export default new Router({
  routes:[
    {
      path:'/home',
      name:'/home',
      component:Home
    },
    {
      path:'/retrieve',
      name:'/retrieve',
      component:Retrieve
    },
    {
      path:'/sort',
      name:'/sort',
      component:Sort
    },
    {
      path:'/docs',
      name:'/docs',
      component:Docs
    },
    {
      path:'/',
      redirect:'/home'
    }
  ]
})