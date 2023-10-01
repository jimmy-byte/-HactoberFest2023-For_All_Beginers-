import java.util.Scanner;

class VirtualPet {
    private String name;
    private int hunger;
    private int happiness;

    public VirtualPet(String name) {
        this.name = name;
        this.hunger = 50;
        this.happiness = 50;
    }

    public String getName() {
        return name;
    }

    public int getHunger() {
        return hunger;
    }

    public int getHappiness() {
        return happiness;
    }

    public void feed() {
        hunger -= 10;
        if (hunger < 0)
            hunger = 0;
    }

    public void play() {
        happiness += 10;
        if (happiness > 100)
            happiness = 100;
    }

    public void tick() {
        hunger += 5;
        happiness -= 5;
        if (hunger > 100)
            hunger = 100;
        if (happiness < 0)
            happiness = 0;
    }
}

public class VirtualPetGame {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your pet's name: ");
        String petName = scanner.nextLine();
        VirtualPet pet = new VirtualPet(petName);

        System.out.println("Welcome to the Virtual Pet Game!");
        System.out.println("You have a pet named " + pet.getName() + ". Take care of your pet!");

        while (true) {
            System.out.println("\n---------------------");
            System.out.println("Pet Status");
            System.out.println("Name: " + pet.getName());
            System.out.println("Hunger: " + pet.getHunger());
            System.out.println("Happiness: " + pet.getHappiness());
            System.out.println("---------------------");
            System.out.println("1. Feed the pet");
            System.out.println("2. Play with the pet");
            System.out.println("3. Do nothing");
            System.out.println("4. Quit");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (choice) {
                case 1:
                    pet.feed();
                    System.out.println("You fed " + pet.getName() + ".");
                    break;
                case 2:
                    pet.play();
                    System.out.println("You played with " + pet.getName() + ".");
                    break;
                case 3:
                    System.out.println("You did nothing.");
                    break;
                case 4:
                    System.out.println("Goodbye! Thanks for playing.");
                    scanner.close();
                    return;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }

            pet.tick(); // Simulate time passing
        }
    }
}
