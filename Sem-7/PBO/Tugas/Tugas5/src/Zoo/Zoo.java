package Zoo;
import java.util.ArrayList;
import java.util.List;

import Hewan.Cow;
import Hewan.Lion;
import Hewan.Parrot;
import Interfaces.Animal;

public class Zoo {
    private List<Animal> animals;

    public Zoo() {
        animals = new ArrayList<>();
    }

    public void addAnimal(Animal animal) {
        animals.add(animal);
    }

    public void feedAnimals() {
        for (Animal animal : animals) {
            animal.eat();
        }
    }

    public void putAnimalsToSleep() {
        for (Animal animal : animals) {
            animal.sleep();
        }
    }

    public void countTotalAnimals() {
        int lions = 0, cows = 0, parrots = 0;
        for (Animal animal : animals) {
            if (animal instanceof Lion) lions++;
            else if (animal instanceof Cow) cows++;
            else if (animal instanceof Parrot) parrots++;
        }
        System.out.println("Total Lions: " + lions);
        System.out.println("Total Cows: " + cows);
        System.out.println("Total Parrots: " + parrots);
    }
}
