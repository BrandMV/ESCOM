<template>
    <div class="container-sub">
        <form class="form-container">
            <div class="text-field">
                <label>Dirección IP</label>
                <input v-model.lazy="ip" placeholder="Dirección IP" required @blur="isIpValid()">
            </div>
            <div class="text-field">
                <label>No. Hosts</label>
                <input v-model.lazy="requireNumber" type="number" placeholder="No. Hosts" required @blur="ipCalcs()" >
            </div>
        </form>
        <div class="cards" v-if=" cards.length > 1">
            <card
                v-for="(card, index) in cards" :key="index"
                :title="card.title"
                :icon="card.icon"
                :value="card.value.toString()"

            >

            </card>
            <button class="calc" @click="subnetsCalc()">calcular</button>
        </div>
        <section class="subnets-list" v-if="hasSubnets">
            <VTable
                title="Lista de Subredes"
                :list="subnetListSubnet"
                @modalShow="showModal = true"
                :calc="hostCalc"
                :pre="prefixSubnet"

            >

            </VTable>
        </section>
          <modal v-if="showModal" @close="showModal = false" :hosts="hostsList"
            :broad="broadcastAdrrSubnet"  
          >
            <h3>custom header</h3>
        </modal>
        <Footer/>
    </div>
</template>
<script>
import Card from '../Card.vue'
import Modal from '../Modal.vue'
import VTable from '../VTable.vue'
import subnetsCalc from "../../mixins/subnetsCalc"
import hostCalc from "../../mixins/hostCalc"
import ipMixin from "../../mixins/ipMixin"
import maskCalc from "../../mixins/maskCalc"
import prefix from "../../mixins/prefix"
import hop from "../../mixins/hop"


export default {
    name: "Subnets",
    components : { Card, Modal, VTable },
    data() {
        return {
            ip: '',
            res: 0,
            octectToModify : 3,              //Variable para saber el octeto de la ip a modificar, por defecto se modifica el último
            requireNumber: 0,
            ipOctects: [],
            completeIP:{},
            expoSubnets: 0,
            gotSubnets: 0,
            hostPow: 0,
            totalHostSubnet: 0,
            newMaskSubnet: [],
            prefixSubnet: 0,
            hopSubnet: 0,
            subnetListSubnet: [],
            hostsList: [],
            broadcastAdrrSubnet: [],
            cards: [],
            hasSubnets: false,
            showModal: false,
            msg: ''
        }
    },
    mixins: [
        subnetsCalc, hostCalc, ipMixin, maskCalc, prefix, hop
    ],
    methods: {

        //Restricciones

        /**
         * Función que verifica que las sub redes requeridas por el usuario sean acordes al tipo de clase de la red
         * @returns Una alerta en caso de solicitar más subredes
        */
        subnetsRestric () {
            console.log(this.completeIP.netClass);
            //  Si es clase A y se requieren mas subredes de las que se pueden crear manda error
            if(this.completeIP.netClass == "Clase A" && this.requireNumber > 16777214){
                this.msg = "Inserte una cantidad de Hosts válida, inserte un valor de 1 a 16777214"
                return true
            } 
                
            //  Si es clase B y se requieren mas subredes de las que se pueden crear manda error
            if(this.completeIP.netClass == "Clase B" && this.requireNumber > 65534){
                this.msg = "Inserte una cantidad de Hosts válida, inserte un valor de 1 a 65534"
                return true
            }
            

            //  Si es clase C y se requieren mas subredes de las que se pueden crear manda error
            if(this.completeIP.netClass == "Clase C" && this.requireNumber > 254){
                this.msg = "Inserte una cantidad de Hosts válida, inserte un valor de 1 a 254"
                return true
             }
            
        },
        /**
         * Función que obtiene los datos como exponentes, nueva mascara, cantidad de hosts y subredes
         * @returns Los calculos hechos con la ip válida
         */
        ipCalcs(){
            this.cards.splice(2)
            if(this.subnetsRestric())
                alert(this.msg)
            else{
                this.hostPow = Math.ceil(Math.log2(this.requireNumber+2))               //  Calculamos la potencia necesaria para calcular los hosts                  
                this.totalHostSubnet =  Math.pow(2,this.hostPow)-2                  //  Calculammos el numero total de hosts que tendra cada subred
                this.expoSubnets = this.completeIP.hostBits - this.hostPow      //  Calculamos el exponente de la subred
                console.log(this.expoSubnets);
                this.gotSubnets = Math.pow(2,this.expoSubnets)                      //  Calculamos la cantidad de subredes totales            
                this.newMaskSubnet = this.getNewMask(this.hostPow)                   //  Mandamos a llamar a la funcion que calcula nueva mascara
                this.prefixSubnet = this.prefixFunc()                // Calculamos el prefijo
                this.hopSubnet = this.hopFunc()      //  Calculamos el salto de cada subred
                this.cards.push({
                    icon:"fas fa-project-diagram", 
                    title: "subredes", 
                    value: this.gotSubnets
                },
                {
                    icon:"fas fa-users", 
                    title: "Hosts", 
                    value: this.totalHostSubnet
                },
                {
                    icon:"fas fa-theater-masks", 
                    title: "nueva máscara", 
                    value: this.newMaskSubnet.join('.')
                }) 
                this.cards.splice(5)

            }
            
        }

    }
}
</script>
 
<style scoped>
   label{
        display: block;
        font-size: 1.6rem;

    }
    .container-sub{
        /* margin-top: 6.9rem; */
     
  
    }
.form-container{
    padding: 0 2rem;
    display: flex;
    justify-content: space-between;
    flex-wrap: wrap;
}
form .text-field{
    position: relative;
    border-bottom: 2px solid #D7816D;
    max-width: 100%;
}
.text-field input{
    max-width: 100%;
    width: 39.2rem;
    /* padding: 0 1rem; */
    height: 5rem;
    font-size: 1.6rem;
    border: none;
    background: none;
    outline: none;
}
.cards{
    margin-top: 5.9rem;
    display: flex;
    flex-wrap: wrap;
    gap: 2.3rem;
    justify-content: center;
}
.calc{
    max-width: 100%;
    width: 30.8rem;
    height: 12.3rem;
    background: #1E1E2A;
    border: 1px solid #D3DCD2;
    box-sizing: border-box;
    box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);
    border-radius: 10px;
    font-size: 3rem;
    color: white;
    text-transform: uppercase;
    font-weight: bold;
    transition: 0.2s ease-in-out;
    cursor: pointer;
}
button:hover{
    transform: translateY(-3%);
}

.subnets-list{
    margin-top: 5rem;
    overflow: auto;
    max-height: 100%;
}
@media (max-width: 400px) {
    .calc{
        font-size: 2.5rem;
    }
}

</style>