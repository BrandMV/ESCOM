<template>
        <transition name="modal">
            <div class="modal-mask">
                <div class="modal-wrapper">
                    <div class="modal-container">
                        <div class="modal-header">
                            <button class="modal-default-button" @click="$emit('close')">
                                X
                            </button>
                        </div>
                        <div class="modal-body">
                          <h3>Dir. de broadcast: {{ broad }}</h3>
                            <VTable
                                title="Lista de Hosts"
                                :list="hosts"
                                @modalShow="showModal = true"
                                
                            >

                            </VTable>
                        </div>

                        <div class="modal-footer">
                  
                        </div>
                    </div>
                </div>
            </div>
        </transition>
</template>
<script>
import VTable from './VTable.vue'

export default {
    name: "modal",
    props: {
        hosts: Array,
        broad: String
    },
    components: { VTable }
    
}
</script>
<style scoped>
.modal-mask {
    display: flex;
    justify-content: center;
    /* align-items: center; */
  position: fixed;
  z-index: 9998;
  top: 0;
  left: 0;
  width: 100%;
  max-width: 100vw;
  background-color: rgba(0, 0, 0, .5);
  max-height: 100vh;
  height: 100%;
    overflow: auto;
  transition: opacity .3s ease;
    /* transform: translateX(50%); */
}

.modal-wrapper {
  /* display: table-cell; */
  /* vertical-align: middle; */


}
/* h3{
  marginbot
} */

.modal-container {
  width: 80rem;
  max-width: 100vw;
  margin: 0px auto;
  padding: 20px 30px;
  background-color: #fff;
  border-radius: 2px;
  box-shadow: 0 2px 8px rgba(0, 0, 0, .33);
  transition: all .3s ease;
  font-family: Helvetica, Arial, sans-serif;

}

 h3 {
  margin-top: 0;
  color: #42b983;
  font-size: 2rem;
  margin-bottom: 1.5rem;
}

.modal-body {
  margin: 20px 0;
}

.modal-default-button {
     background: none;
        font-size: 2rem;
        font-weight: bold;
        margin-bottom: .8rem;
        float: right;
        border: none;
        cursor: pointer;
        color: red;
    }

    /*
    * The following styles are auto-applied to elements with
    * transition="modal" when their visibility is toggled
    * by Vue.js.
    *
    * You can easily play with the modal transition by editing
    * these styles.
    */

    .modal-enter {
    opacity: 0;
    }

    .modal-leave-active {
    opacity: 0;
    }

    .modal-enter .modal-container,
    .modal-leave-active .modal-container {
    -webkit-transform: scale(1.1);
    transform: scale(1.1);
    }

</style>