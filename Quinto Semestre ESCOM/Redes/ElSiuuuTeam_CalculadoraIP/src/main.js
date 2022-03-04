import { createApp } from 'vue'
import App from './App.vue'
import VueToast from 'vue-toast-notification';
import '../src/assets/css/global.css'
import 'vue-toast-notification/dist/theme-sugar.css';

createApp(App).use(VueToast).mount('#app')
