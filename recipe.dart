// Define a Recipe class to represent a recipe
class Recipe {
  constructor(name, ingredients, instructions, cookingTime) {
    this.name = name;
    this.ingredients = ingredients;
    this.instructions = instructions;
    this.cookingTime = cookingTime; // New property for cooking time
  }

  // Method to display recipe details
  displayRecipe() {
    console.log(`Recipe: ${this.name}`);
    console.log(`Ingredients: ${this.ingredients.join(', ')}`);
    console.log(`Instructions: ${this.instructions}`);
    console.log(`Cooking Time: ${this.cookingTime} minutes`); // Display cooking time
  }
}

// Create a sample recipe
const pastaRecipe = new Recipe(
  'Pasta Carbonara',
  ['Spaghetti', 'Eggs', 'Pancetta', 'Parmesan Cheese'],
  '1. Cook pasta. 2. Fry pancetta. 3. Mix eggs and cheese. 4. Combine all.',
  20 // Cooking time in minutes
);

// Display the recipe
pastaRecipe.displayRecipe();
