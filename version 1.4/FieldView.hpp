#ifndef FIELD_VIEW_HPP
#define FIELD_VIEW_HPP

#include"Field.hpp"
#include<SFML/Graphics.hpp>
#include<map>
#include<initializer_list>

enum class OutMode { CLI, GUI };

class FieldView {
public:
    FieldView(OutMode md = OutMode::GUI);
    ~FieldView(){}
    FieldView& operator<<(Field& field);
    // FieldView& operator<<(Field* field);
    // FieldView& operator<<(FieldView& a, Field& field);

    void Mode(OutMode md);
    void loadPictures(std::initializer_list<std::string> fpList);

private:
    OutMode mode;
    std::map<Type, std::string> filePaths;

};


#endif //FIELD_VIEW_HPP