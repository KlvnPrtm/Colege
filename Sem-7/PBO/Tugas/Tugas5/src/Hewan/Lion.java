package Hewan;
import Interfaces.Animal;

public class Lion implements Animal{

    @Override
    public void eat() {
        System.out.println("Lion is eating.");
    }

    @Override
    public void sleep() {
        System.out.println("Lion is sleeping.");
    }

    @Override
    public void makeSound() {
        System.out.println("Lion roars.");
    }

}
