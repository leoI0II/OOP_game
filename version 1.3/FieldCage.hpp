#ifndef FIELDCAGE_HPP
#define FIELDCAGE_HPP

#include"IFieldCage.hpp"

enum class Status { NOT_AVAILABLE, AVAILABLE };
enum class Type { Exit, Common, Entry, Wall };

class FieldCage : public IFieldCage {
private:
    int x_coord;
    int y_coord;

    Type type;
    Status status;

public:
    FieldCage(int x = 0, int y = 0, Type tp = Type::Common, Status st = Status::NOT_AVAILABLE);
    ~FieldCage() {}

    Status& cageStatus();
    Type& cageType();

    int getX() const;
    FieldCage& setX(int x);

    int getY() const;
    FieldCage& setY(int y);

    void method();
};


#endif //FIELDCAGE_HPP