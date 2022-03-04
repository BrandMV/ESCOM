<template>
    <div>
        <h2>{{title}}</h2>
        <table>
                <tr>
                    <th>id</th>
                    <th>dirección</th>
               </tr>
           <tbody v-for="(sub, index) in list" :key="index" > 
                <tr>
                    <td> {{ index+1 }} </td>
                    <td @click="calc(sub), $emit('modalShow')" style="cursor: pointer" > {{ sub.join('.') }}/{{ pre }} </td>
                </tr> 
            </tbody>
        </table>
    </div>
</template>
<script>
export default {
    name: "VTable",
    props: { title: String, list: Array, calc: Function, pre:Number},
    methods: {
        openModal(){
            this.$emit()
        }
    }
}
</script>
<style scoped>
    h2{
    text-transform: uppercase;
    font-size: 2.5rem;
    font-weight: bold;
    text-align: center;
}
table {
  border-collapse: collapse;
  width: 100%;
  text-align: center;
  font-size: 1.8rem;
}

th{
    font-weight: bold;
    text-transform: uppercase;
}
td,th{
    border: 1px solid #C0C0C0;
    padding: 1rem;
}
tr:nth-child(even) {
  background-color: #dddddd;
}
</style>