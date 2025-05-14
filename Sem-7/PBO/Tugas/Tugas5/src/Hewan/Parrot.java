package Hewan;
import Interfaces.Animal;

public class Parrot implements Animal{

    @Override
    public void eat() {
        System.out.println("Parrot is eating.");
    }

    @Override
    public void sleep() {
        System.out.println("Parrot is sleeping.");
    }

    @Override
    public void makeSound() {
        System.out.println("Parrot squawks.");
    }

}
