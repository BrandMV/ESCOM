<template>
    <div class="form-container">
        <form>
            <div class="text-field">
                <input v-model.lazy="userIP" placeholder="Dirección IP" required>
                <p>IPP {{ userIP }}</p>
            </div>
            <div class="text-field">
                <input type="number" :placeholder="title" required>
            </div>
        </form>

    </div>
</template>

<script>
export default {
    name:"input-field",
    props: {
        title: String,
    },
    data() {
        return {
            userIP: ''
        }
    },
}
</script>

<style scoped>
.form-container form{
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




</style>