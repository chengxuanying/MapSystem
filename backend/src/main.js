import Vue from 'vue'
import VCharts from 'v-charts'
//import './element/index.css'
import ElementUI from 'element-ui';
import 'element-ui/lib/theme-chalk/index.css';
import App from './App.vue'
import router from './router'

//import store from './store'

Vue.config.productionTip = false;
Vue.use(ElementUI);
Vue.use(VCharts);


new Vue({
  el: '#app',
  router,
  render: h => h(App)
})