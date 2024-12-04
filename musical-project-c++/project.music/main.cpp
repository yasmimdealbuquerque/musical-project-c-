#include <iostream> 
#include <conio.h> 
#include <windows.h> 
#include <locale.h>
#include <fstream> 
#include <string>

using namespace std;

void playNotes(int freq, int tempo){
    if (freq > 0){
        Beep(freq, tempo);
    }
}

void guitarraVirtual(string& musicDados){
   while (true){
    char notes = _getch();

    switch (notes){
        case 'q':
            playNotes(82, 350);
            musicDados += "82 350\n";
            break;
        case 'w':
            playNotes(110, 350);
            musicDados += "110 350\n";
            break;
        case 'e':
            playNotes(146, 350);
            musicDados += "146 350\n";
            break;
        case 'r':
            playNotes(196, 350);
            musicDados += "196 350\n";
            break;
        case 't':
            playNotes(246, 350);
            musicDados += "246 350\n";
            break;
        case 'y':
            playNotes(329, 350);
            musicDados += "329 350\n";
            break;
        case 'b':
            cout << "" << '\n'
                 << "Não quer mais tocar guitarra ?" << "\n"
                 << "Bom, você não é um Jimmy Page, mas continue tentando ^-^"<< "\n"
                 << "Sua música está sendo gravada, aguarde '-' " << endl;
                  system("pause");
                  system("cls");
            return;
           
        default:
            cout << "Bem, parece que teclou errado... -_-" << endl;
            break; 
    }
   }
}

void bateriaVirtual(string& musicDados){
    while(true){
        char notes = _getch();

            switch (notes){
        case '7':
            playNotes(200, 300); // caixa
            musicDados += "200 350\n"; 
            break;
        case '8':
            playNotes(115, 300); // tom grave
            musicDados += "115 350\n";
            break;
        case '9':
            playNotes(180, 300); // tom medio
            musicDados += "180 350\n";
            break;
        case '4':
            playNotes(280, 300); // tom agudo
            musicDados += "280 350\n";
            break;
        case '5':
            playNotes(80, 300); // bumbo
            musicDados += "80 350\n";
            break;
        case '6':
            playNotes(5000, 300); // hi-hat
            musicDados += "5000 350\n";
            break;
        case '2':
            playNotes(5500, 300); // prato
            musicDados += "5500 350\n";
            break;
        case '0':
            cout << "Éhhh... o Eloy Casagrande ainda é melhor, mas tudo bem °l°"<< "\n"
                << "Estamos terminando de gravar seu som, um segundo :}" << endl;
                system("pause");
                system("cls");
            return;
        default:
            cout << "Bem, parece que é melhor você tentar mais tarde... ^-^'" << endl;
            break; 
        }
    }
    
}

void saveMusic(const string nameFile, const string musicDados){
    ofstream saveArquivo(nameFile, ofstream::out);
    if(!saveArquivo){
        cout << "Poxa, não conseguimos abrir o arquivo para salva sua música..." << endl;
        return;
    }

    saveArquivo << musicDados << endl;
    if (saveArquivo.is_open()){
        cout << "Música salva, hehe :D" << endl; 
    }else{
        cout <<"Vish, deu erro ao salvar ¨_¨ "<<endl;
    }
    saveArquivo.close();
}

void playMusic(const string nameFile){
    ifstream musicFile(nameFile);
    if (musicFile.is_open()){
        cout <<"Abrindo o arquivo com sua música..." << endl;
    }else{
        cout << "Não conseguimos abrir o arquivo com sua música :(" << endl;
        system("pause");
        system("cls");  
        return;
    }

    int freq, tempo;
    while (musicFile >> freq >> tempo){
        playNotes(freq, tempo);
    }
    musicFile.close();
    cout << "Olhaaa, que música hein, já podes ir sangrar os ouvidos das pessoas no rock in rio ;)"<< endl;
    system("pause");
    system("cls");
    
}

int main (){

    setlocale(LC_ALL, "pt_BR.UTF-8");
	SetConsoleOutputCP(CP_UTF8);
    system("color 0D");

    
    char escolha;
    do { // é pra rodar o bloco baixo várias vezes, mas ele vai testar antes 
        system("cls");
        cout << " " << endl;
        cout << "Aoba, esse é nosso 'joguinho' musical, seja bem vindo!" << endl;
        cout << "Temos dois instrumentos diferentes pra tocar"<< endl;
        cout << " " << endl;
        cout << "Faça sua escolha e aperte 'enter' " << endl;
        cout << "1 - Guitarra" << endl;
        cout << "2 - Bateria" << endl;
        cout << "3 - Reproduzir música" << endl;
        cout << "4 - Sair do joguinho" << endl;

        cin >> escolha;
        string nameMusic;

        if (escolha == '1' || escolha == '2'){
            string nameMusic;
            cout << "Qual o nome da sua música ? (digite sem espaços): ";
            cin >> nameMusic;

            string nameFile = nameMusic + ".txt";
            string musicDados = "";
       

            if (escolha == '1'){
                cout << "Pode tocar sua guitarra " << endl;
                cout << "Teclas: de q a y" << endl;
                cout << "Encerrar: b" << endl;
                guitarraVirtual(musicDados);
                
                

            }else if(escolha == '2'){
                cout <<"Pode tocar sua bateria"<< endl;
                cout << "Teclas: de 7 a 1" << endl;
                cout << "Encerrar: 0" << endl;
                bateriaVirtual(musicDados);
                
                
        }

        saveMusic(nameFile, musicDados);

        }else if (escolha == '3'){
           string nameMusic;
           cout << "Qual música você quer reproduzir?: ";
           cin >> nameMusic;
           
           string nameFile = nameMusic + ".txt"; 
           playMusic(nameFile);

        }else if (escolha == '4'){
            cout << "Obrigada por tocar, não esqueça de praticar L(^^)" << endl;
            cout << "Volte sempre meu patrão :) :)" << endl;
            system("pause");
            system("cls");
        }else {
            cout <<"Escolhe algo que existe cara, pfvr..."<< endl;
        
        }
        system("cls");
    }while(escolha != '4');
    return 0; 
}