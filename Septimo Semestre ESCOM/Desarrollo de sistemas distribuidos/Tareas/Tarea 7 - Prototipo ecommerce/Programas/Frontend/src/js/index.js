const URL = "/Servicio/rest/ws";
let photo;
let products = []
let productsInCar = []

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
    var element = document.getElementById("toastAddProduct");
    var myToast = new bootstrap.Toast(element);
    myToast.show()
    cliente.postJson("altaArticulo", {
        Articulo: Articulo
    },
    function(code, result){
        if(code == 200){
            var element = document.getElementById("toastAddProduct");
            var myToast = new bootstrap.Toast(element);
            myToast.show()
        }else{
            alert(JSON.stringify(result));
        }
    })
    $('#addProductForm').trigger("reset");
}

function buscaArticulo(){
    let cliente = new WSClient(URL)
    
    // products.push(Product)
    // products.push(Product2)
    // products.push(Product2)
    // products.push(Product)
    // products.push(Product)
    // console.log(products)
    // products.forEach(element => {
    //                 let card = `
    //                             <div class="card" style="width: 18rem;">
    //                                 <img class="card-img-top" id="productImage" src="data:image/jpeg;base64,${element.Foto}" alt="${element.Nombre}">
    //                                 <div class="card-body">
    //                                     <h5 class="card-title">${element.Nombre} - ${element.Precio} MXN</h5>
    //                                     <form class="mt-3 mb-3">
    //                                         <div class="row">
    //                                         <div class="col-4">
    //                                             <input class="form-control" type="number" name="productQuantity" id="productQuantity${element.Id}" step="1" value="1" min="0">
    //                                         </div>
    //                                         <div class="col-8">
    //                                             <button type="button" class="btn btn-info" onclick=addToCar(${element.Id})>Añadir al carrito</button>
    //                                         </div>
    //                                         </div>
    //                                     </form>
    //                                     <button type="button" data-bs-toggle="modal" data-bs-target="#descripcionProducto${element.Id}" class="btn btn-primary">Ver descripción</button>
    //                                 </div>
    //                             </div>
    //                             <!-- Modal -->
    //                             <div class="modal fade" id="descripcionProducto${element.Id}" tabindex="-1" role="dialog" aria-labelledby="exampleModalCenterTitle" aria-hidden="true">
    //                             <div class="modal-dialog modal-dialog-centered" role="document">
    //                                 <div class="modal-content">
    //                                 <div class="modal-header">
    //                                     <h5 class="modal-title" id="exampleModalLongTitle">Descripción del producto</h5>
    //                                     <button type="button" class="close" data-bs-dismiss="modal" aria-label="Close">
    //                                     <span aria-hidden="true">&times;</span>
    //                                     </button>
    //                                 </div>
    //                                 <div class="modal-body">
    //                                     ${element.Descripcion}
    //                                 </div>
    //                                 <div class="modal-footer">
    //                                     <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cerrar</button>
    //                                 </div>
    //                                 </div>
    //                             </div>
    //                             </div>
    //                             `
    //             $("#productImage").src="data:image/jpeg;base64," + element.Foto
    //             $("#showProducts").append(card);

    //             });
    
    cliente.postJson("buscarArticulo",
    {
        PalabraCalve: $("#searchProductInput").val()
    },
    function(code, result){
        if(code == 200){
            products = []
            $("#showProducts").empty()
            console.log(result)
            products = result
            products.forEach(element => {
                let card = `
                                <div class="card" style="width: 18rem;">
                                    <img class="card-img-top" id="productImage" src="data:image/jpeg;base64,${element.Foto}" alt="${element.Nombre}">
                                    <div class="card-body">
                                        <h5 class="card-title">${element.Nombre} - ${element.Precio} MXN</h5>
                                        <form class="mt-3 mb-3">
                                            <div class="row">
                                            <div class="col-4">
                                                <input class="form-control" type="number" name="productQuantity" id="productQuantity${element.Id}" step="1" value="1" min="0">
                                            </div>
                                            <div class="col-8">
                                                <button type="button" class="btn btn-info" onclick=addToCar(${element.Id})>Añadir al carrito</button>
                                            </div>
                                            </div>
                                        </form>
                                        <button type="button" data-bs-toggle="modal" data-bs-target="#descripcionProducto${element.Id}" class="btn btn-primary">Ver descripción</button>
                                    </div>
                                </div>
                                <!-- Modal -->
                                <div class="modal fade" id="descripcionProducto${element.Id}" tabindex="-1" role="dialog" aria-labelledby="exampleModalCenterTitle" aria-hidden="true">
                                <div class="modal-dialog modal-dialog-centered" role="document">
                                    <div class="modal-content">
                                    <div class="modal-header">
                                        <h5 class="modal-title" id="exampleModalLongTitle">Descripción del producto</h5>
                                        <button type="button" class="close" data-bs-dismiss="modal" aria-label="Close">
                                        <span aria-hidden="true">&times;</span>
                                        </button>
                                    </div>
                                    <div class="modal-body">
                                        ${element.Descripcion}
                                    </div>
                                    <div class="modal-footer">
                                        <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">Cerrar</button>
                                    </div>
                                    </div>
                                </div>
                                </div>
                                `
                $("#productImage").src="data:image/jpeg;base64," + element.Foto
                $("#showProducts").append(card);
            });
        }else{
            alert(JSON.stringify(result));
        }
    })
}

function verCarrito(){
    let cliente = new WSClient(URL)
    productsInCar = []
    // $("#carItemsTable tbody").empty()
    // productsInCar.forEach(element => {
    //     let itemTr = `
    //                     <tr id="productRow${element.Id}">
    //                         <td>${element.Nombre}</td>
    //                         <td>${element.Cantidad}</td>
    //                         <td>$${element.Precio}MXN</td>
    //                         <td>$${element.Precio * element.Cantidad}MXN</td>
    //                         <td><img src="data:image/jpeg;base64,${element.Foto}" width="150rem" height="150rem" alt=""></td>
    //                         <td><button class="btn btn-danger" id="deleteProducto${element.Id}" onclick="deleteProduct(${element.Id})">Eliminar</button></td>
    //                     </tr>
    //                 `
    //     $("#carTableBody").append(itemTr)
    //     let total = productsInCar.reduce((acc, p) => acc + (p.Precio * p.Cantidad), 0)
    //             console.log(total);
    //             $("#totalPrice").text("Subtotal: $" + total + "MXN")
    // });
    $("#carNotFound").text("")

    cliente.postJson("verCarrito", {}, function(code, result){
        if(code == 200){
            $("#carItemsTableWraper").removeClass("d-none")
            productsInCar = []
            $("#carItemsTable tbody").empty()
            productsInCar = result;
            productsInCar.forEach(element => {
                let itemTr = `
                                <tr id="productRow${element.Id}">
                                    <td>${element.Nombre}</td>
                                    <td>${element.Cantidad}</td>
                                    <td>$${element.Precio}MXN</td>
                                    <td>$${element.Precio * element.Cantidad}MXN</td>
                                    <td><img src="data:image/jpeg;base64,${element.Foto}" width="150rem" height="150rem" alt=""></td>
                                    <td><button class="btn btn-danger" id="deleteProducto${element.Id}" onclick="deleteProduct(${element.Id})">Eliminar</button></td>
                                </tr>
                            `
                $("#carTableBody").append(itemTr)
                let total = productsInCar.reduce((acc, p) => acc + (p.Precio * p.Cantidad), 0)
                console.log(total);
                $("#totalPrice").text("Subtotal: $" + total + "MXN")
            });
        }else{
            $("#carItemsTableWraper").addClass("d-none")
            $("#carNotFound").text(JSON.stringify(result))
        }
    })
}

function deleteProduct(Id){
    let cliente = new WSClient(URL)
    let ParamEliminarArticuloCarrito = {
        Id: Id
    }
    cliente.postJson("eliminarArticuloCarrito",{
        ParamEliminarArticuloCarrito: ParamEliminarArticuloCarrito
    }, function(code, result){
        if(code == 200){
            var element = document.getElementById("liveToastDeleteProduct");
            var myToast = new bootstrap.Toast(element);
            myToast.show()
            $("table#carItemsTable tr#productRow"+Id).remove()
        }else{
            alert(JSON.stringify(result))
        }
    })
}
function addToCar(productId){
    let quantity = $("#productQuantity" + productId).val()
    console.log(productId);
    console.log(quantity)

    let cliente = new WSClient(URL)
    let ParamAgregarCarrito = {
        Id: productId,
        Cantidad: quantity
    }
    cliente.postJson("agregarCarrito",{
        ParamAgregarCarrito: ParamAgregarCarrito
    },
    function(code, result){
        if(code == 200){
            // Create toast instance
            var element = document.getElementById("liveToast");
            var myToast = new bootstrap.Toast(element);
            myToast.show()
        }else{
            var element = document.getElementById("liveToastError");
            var myToast = new bootstrap.Toast(element);
            $("#toastErrorBody").text(JSON.stringify(result))
            myToast.show()
        }
            
    })
}

function BorrarCarrito(){
    let cliente = new WSClient(URL)
    cliente.postJson("borrarCarrito", {}, function(code, result){
        if(code == 200){
            $("#carItemsTableWraper").addClass("d-none")
            $("#carNotFound").text("No tienes artículos en tu carrito")
        }else{
            alert(JSON.stringify(result))
        }
    })
}

$("#photo").on("change", function(e){
    photo = $("#photo")
    let files = photo.prop('files')
    readSingleFile(files, photo);
})

$("#homeButton").on("click", function(){
    $("#buyProductsSection").addClass("d-none")
    $("#buyProductsSection").removeClass("d-block")
    $("#mainPage").addClass("d-block")
    $("#mainPage").removeClass("d-none")
})
$("#addProduct").on("click", function(e){
    e.preventDefault();
    altaArticulio()
})
$("#buyProductPage").on("click", function(){
    $("#buyProductsSection").removeClass("d-none")
    $("#buyProductsSection").addClass("d-block")
    $("#mainPage").removeClass("d-block")
    $("#mainPage").addClass("d-none")

})
$("#searchProduct").on("click", function(e){
    e.preventDefault();
    buscaArticulo()
})
$("#seeCar").on("click", function(e){
    e.preventDefault()
    $("#buyProductsSection").removeClass("d-block")
    $("#buyProductsSection").addClass("d-none")
    $("#carPage").removeClass("d-none")
    $("#carPage").addClass("d-block")
    
    verCarrito()
})

$("#AddProductPage").on("click", function(){
    $("#mainPage").addClass("d-none")
    $("#addProductForm").removeClass("d-none");
    $("#addProductForm").addClass("d-block")

})
$("#mainButton").on("click", function(){
    $("#mainPage").addClass("d-block")
    $("#mainPage").removeClass("d-none")
    $("#addProductForm").removeClass("d-block");
    $("#addProductForm").addClass("d-none")
})

$("#continueBuyingBtn").on("click", function(){
    $("#buyProductsSection").addClass("d-block")
    $("#buyProductsSection").removeClass("d-none")
    $("#carPage").addClass("d-none")
    $("#carPage").removeClass("d-block")
})

$("#deleteCarBtn").on("click", function(){
    BorrarCarrito()
})
