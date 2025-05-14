package Hewan;
import Interfaces.Animal;

public class Cow implements Animal{

    @Override
    public void eat() {
        System.out.println("Cow is eating.");
    }

    @Override
    public void sleep() {
        System.out.println("Cow is sleeping.");
    }

    @Override
    public void makeSound() {
        System.out.println("Cow moos.");
    }

}
