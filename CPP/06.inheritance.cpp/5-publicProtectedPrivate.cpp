/**
 * * if a class inherits from another as public:
 *  public of base is       public in derived
 *  protected of base is    protected in derived
 * * if a class inherits from another as private:
 *  public of base is       private in derived
 *  protected of base is    private in derived
 * * if a class inherits from another as protected:
 *  public of base is       protected in derived
 *  protected of base is    protected in derived
 * *difference detween protected and private
 *  1. private members are not inherited
 *  2. protected members are inherited and can be accessed from derived class
 *  3. both cant be accessed outside the class
 * *whenever the need to never let some members be inherited from a drived class
 *  use private inheritance
 */
class Base {
public:
    int publicMember;
protected:
    int protectedMember;
private:
    int privateMember;
};

// Public inheritance
class DerivedPublic : public Base {
    // publicMember is accessible
    // protectedMember is accessible
    // privateMember is not accessible
};

// Private inheritance
class DerivedPrivate : private Base {
    // publicMember is accessible
    // protectedMember is accessible
    // privateMember is not accessible
};

// Protected inheritance
class DerivedProtected : protected Base {
    // publicMember is  accessible
    // protectedMember is accessible
    // privateMember is not accessible
};

int main(int argc, char const *argv[])
{
    DerivedPublic dPublic;
    DerivedPrivate dPrivate;
    DerivedProtected dProtected;

    dPublic.publicMember = 1;
    //dPublic.protectedMember = 2;
    // dPublic.privateMember = 3; // error

    //dPrivate.publicMember = 1;
    //dPrivate.protectedMember = 2;
    // dPrivate.privateMember = 3; // error

    //dProtected.publicMember = 1;
    return 0;
}
