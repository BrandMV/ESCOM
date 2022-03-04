<template>
    <div class="card">
        <i :class="icon"></i>
        <div class="card-content">
            <h3>{{ title }}</h3>
            <p>{{ value }}</p>
        </div>
    </div>
</template>
<script>
export default {
    name: "card",
    props: {
        title: String,
        value: String,
        icon: String
    }
}
</script>
<style>
    .card{
        max-width: 100%;
        width: 30.8rem;
        height: 12.3rem;
        background: white;
        border: 1px solid #D3DCD2;
        box-sizing: border-box;
        box-shadow: 0px 4px 4px rgba(0, 0, 0, 0.25);
        border-radius: 10px;
        display: flex;
        align-items: center;
        gap: 2.6rem;
        padding: 1.5rem;
        transition: 0.2s ease-in-out;

    }
    .card-content{
        display: flex;
        flex-direction: column;
    }
    h3{
        font-size: 2.2rem;
        font-weight: 300;
        text-transform: uppercase;
    }
    p{
        font-size: 2.2rem;
        font-weight: bold;
    }
    i{
        font-size: 4rem;
        color: black;
    }
    .card:hover{
        transform: translateY(-3%);
    }

    @media (max-width: 790px) {
        .card{
            height: 15rem;
            gap: 1rem;
            flex-direction: column;
            justify-content: center;
            align-items: center;
        }
        .card-content{
            align-items: center;
        }
    }
    @media (max-width: 400px) {
        h3,p{
            font-size: 2rem;
        }
        i{
            font-size: 3rem;
        }
    }
</style>