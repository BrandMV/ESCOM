import React, { useEffect } from "react";
import { useDispatch, useSelector } from "react-redux";
import { getProductsBySlug } from "../../../actions";
import { Link } from "react-router-dom";
import Rating from "../../../components/UI/Rating";
import { generatePublicUrl } from "../../../urlConfig";
import "./style.css"

const ProductStore = (props) => {
  const product = useSelector((state) => state.product);
  const priceRange = product.priceRange;
  const dispatch = useDispatch();

  useEffect(() => {
    const { match } = props;
    dispatch(getProductsBySlug(match.params.slug));
  }, []);

  return (
    <>
       {/* <div className="row row-2">
                <h2>Productos</h2>
                <select>
                  <option>Por defecto</option>
                  <option>Ordenar de mayor a menos precio</option>
                  <option>Ordenar de menor a mayor precio</option>
                </select>
      </div> */}
      {Object.keys(product.productsByPrice).map((key, index) => {
        return (
          <div className="small-container" key={index}>
           
            <div className="row">
              {product.productsByPrice[key].map((product, index) => (
                <Link
                  to={`/${product.slug}/${product._id}/p`}
                  key={index}
                  className="col-4"
                >
                    <img
                      src={generatePublicUrl(product.productPictures[0].img)}
                      alt=""
                    />
                    <h4>{product.name}</h4>
                    <div>
                      <Rating value="5" />
                    </div>
                    <p>{product.price} MXN</p>  
                </Link>
              ))}
            </div>
          </div>
        );
      })}
    </>
  );
};

export default ProductStore;
