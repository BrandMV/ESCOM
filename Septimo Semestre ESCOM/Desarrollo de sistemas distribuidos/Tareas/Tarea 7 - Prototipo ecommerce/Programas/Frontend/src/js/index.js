const URL = "/Servicio/rest/ws";
let photo;

function readSingleFile(files,imagen)
			{
				var file = files[0];
				if (!file) return;
				var reader = new FileReader();
				reader.onload = function(e)
				{
					imagen.src = reader.result;
					// reader.result incluye al principio: "data:image/jpeg;base64,"
					photo = reader.result.split(',')[1];
				};
				reader.readAsDataURL(file);
            }
			
function altaArticulio(){
    let cliente = new WSClient(URL)
    let Articulo = {
        Id: 0,
        Nombre: $("#name").val(),
        Descripcion: $("#description").val(),
        Precio: $("#price").val() * 1,
        Cantidad: $("#quantity").val() * 1,
        Foto: photo
    }

    console.log(Articulo);
    // cliente.postJson("altaArticulo", {
    //     Articulo: Articulo
    // },
    // function(code, result){
    //     if(code == 200){
    //         alert("OK")
    //     }else{
    //         alert(JSON.stringify(result));
    //     }
    // })
    $('#addProductForm').trigger("reset");
}

$("#photo").on("change", function(e){
    photo = $("#photo")
    let files = photo.prop('files')
    readSingleFile(files, photo);
})

$("#addProduct").on("click", function(e){
    e.preventDefault();
    altaArticulio()
})

$("#AddProductPage").on("click", function(){
    $("#mainPage").addClass("d-none")
    $("#addProductForm").removeClass("d-none");
    $("#addProductForm").addClass("d-block")

})