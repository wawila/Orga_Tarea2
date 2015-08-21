#include <QCoreApplication>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //ifstream texto("C:\\Users\\David Chavarria\\Documents\\Orga Archivos\\InterpretadorTexto\\TextoSinInterpretar.txt", ios::binary| ios::in);
    fstream txt;
    txt.open("C:\\Users\\David Chavarria\\Documents\\Orga Archivos\\InterpretadorTexto\\Escritor.txt", ios::binary | ios::in | ios::out);


    bool done = false;
    int op;
    string input;

    if(txt.is_open())
        while(!done)
        {
            cout<<"Ingresar Dato: \n 1 - Nombre(10 Chars) \n 2 - Apellido(15 Chars) \n 3 - Edad(2 Chars) \n 4 - Nuevo Item \n 5 - Salir " <<endl;
            cin >> op;

            switch(op)
            {
            case 1:
                cout << "Nombre (10 Chars): ";
                txt << "|n";
                cin >> input;
                for(unsigned int i = 0; i<input.size(); i++)
                    txt << input[i];
                for(unsigned int j = 0; j < 10 - input.size(); j++)
                    if((10 - input.size()) > 0)
                        txt << " ";
                break;
            case 2:
                cout << "Apellid (15 Chars): ";
                txt << "|a";
                cin >> input;
                for(unsigned int i = 0; i<input.size(); i++)
                    txt << input[i];
                for(unsigned int j = 0; j < 15 - input.size(); j++)
                    if((15 - input.size()) > 0)
                        txt << " ";
                break;
            case 3:
                cout << "Edad (2 Chars): ";
                txt << "|e";
                cin >> input;
                for(unsigned int i = 0; i<input.size(); i++)
                    txt << input[i];
                for(unsigned int j = 0; j < 2 - input.size(); j++)
                    if((2 - input.size()) > 0)
                        txt << " ";
                break;
            case 4:
                txt << "|";
                break;
            default:
                txt << "|||";
                done = true;
                break;

            }

        }

    txt.seekg(0, ios::end);
    int size = txt.tellg();

    txt.seekg(0, ios::beg);
    char* data = new char[size];

    txt.read(data, size);

    cout<<endl<<"-------------------------------------------------------------------------"<<endl;


    for(int i = 0; i < size; i++)
    {
        if(data[i] == '|' && data[i+1] == 'n')
        {
            cout<<"Nombre: ";
            for(int j = i+1+1; j < i+10+1; j++)
                cout<<data[j]<<flush;

            cout<<"\t"<<flush;
        }else if(data[i] == '|' && data[i+1] == 'a')
        {
            cout<<"Apellido: ";
            for(int j = i+1+1; j < i+15+1; j++)
                cout<<data[j]<<flush;

            cout<<"\t"<<flush;
        }else if(data[i] == '|' && data[i+1] == 'e')
        {
            cout<<"Edad: ";
            for(int j = i+1+1; j < i+4; j++)
                cout<<data[j]<<flush;

            cout<<"\t"<<flush;
        }else if(data[i] == '|' && data[i+1] == '|' && data[i+2] != '|')
        {
            cout<<endl;
        } else if(data[i] == '|' && data[i+1] == '|' && data[i+2] == '|')
        {
            txt.close();
            break;
        }

    }



    return a.exec();
}
