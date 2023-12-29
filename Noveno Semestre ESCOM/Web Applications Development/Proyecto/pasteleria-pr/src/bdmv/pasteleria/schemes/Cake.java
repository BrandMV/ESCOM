package bdmv.pasteleria.schemes;

import java.util.Arrays;

public class Cake {
	private int id;
	private String name;
	private String size;
	private String image;
	private float price;
	private String ingredients;
	private int people_quantity;
	private String description;
	public Cake() {
		super();
	}
	public Cake(int id, String name, String size, String image, float price, String ingredients, int people_quantity,
			String description) {
		super();
		this.id = id;
		this.name = name;
		this.size = size;
		this.image = image;
		this.price = price;
		this.ingredients = ingredients;
		this.people_quantity = people_quantity;
		this.description = description;
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getSize() {
		return size;
	}
	public void setSize(String size) {
		this.size = size;
	}
	public String getImage() {
		return image;
	}
	public void setImage(String image) {
		this.image = image;
	}
	public float getPrice() {
		return price;
	}
	public void setPrice(float price) {
		this.price = price;
	}
	public String getIngredients() {
		return ingredients;
	}
	public void setIngredients(String ingredients) {
		this.ingredients = ingredients;
	}
	public int getPeople_quantity() {
		return people_quantity;
	}
	public void setPeople_quantity(int people_quantity) {
		this.people_quantity = people_quantity;
	}
	public String getDescription() {
		return description;
	}
	public void setDescription(String description) {
		this.description = description;
	}
	@Override
	public String toString() {
		return "Cake [id=" + id + ", name=" + name + ", size=" + size + ", image=" + image + ", price="
				+ price + ", ingredients=" + ingredients + ", people_quantity=" + people_quantity + ", description="
				+ description + "]";
	}
	
}
