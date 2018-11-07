#pragma once
#define vtkRenderingCore_AUTOINIT 2(vtkRenderingOpenGL2, vtkInteractionStyle)

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkUnstructuredGrid.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkXMLGenericDataObjectReader.h>
#include <vtkUnstructuredGridReader.h>
#include <string>
#include <sstream>
///#include <vtkGenericDataObjectReader.h>

int exportMNOdes(string file){

    ifstream fileIn;
    fileIn.open(file);
    string line;
    std::vector<std::vector<string> > content_parseado;
    int count_line_blank=0;

     while (getline(fileIn,line))
    {

        string item;
        std::stringstream sstr(line);
        std::vector<string> line_parsed;
        
        if (line == ""){
           count_line_blank++;
           cout<<line<<endl;
        } 
        if (count_line_blank == 2)
        {
            break;
        }

        // Read in an item
        
        while (getline(sstr, item, ' '))
        {
            line_parsed.push_back(item);
        }
        content_parseado.push_back(line_parsed);
        
    }
    cout<<"c:"<<count_line_blank<<endl;
    
    ofstream cout("out.mNodes");
    for (int i = 6; i < content_parseado.size(); ++i)
    //or (int i = 6; i < 8; ++i)
    {   
            string x_ = content_parseado[i][1];
            string y_ = content_parseado[i][0];
            
            cout<<"["<<x_<<","<<y_<<"], ";
    }
    cout.close();
	return 1;
}

int execute( string inputFilename){

	// Get all data from the file
		vtkSmartPointer<vtkUnstructuredGridReader> reader =
			vtkSmartPointer<vtkUnstructuredGridReader>::New();
		reader->SetFileName(inputFilename.c_str());
		cout<<inputFilename.c_str()<<endl;
		//reader->SetFileName(inputFilename);
		reader->Update();

		// All of the standard data types can be checked and obtained like this:
		if (vtkPolyData::SafeDownCast(reader->GetOutput()))	{
			std::cout << "File is a polydata" << std::endl;
		}
		else if (vtkUnstructuredGrid::SafeDownCast(reader->GetOutput())){
			std::cout << "File is an unstructured grid" << std::endl;
		}
		
		if(reader->IsFileUnstructuredGrid())
			std::cout<<"si\n";
		else
			std::cout << "no\n";

	// Visualize
		vtkSmartPointer<vtkDataSetMapper> mapper =
			vtkSmartPointer<vtkDataSetMapper>::New();
		mapper->SetInputConnection(reader->GetOutputPort());

		vtkSmartPointer<vtkActor> actor =
			vtkSmartPointer<vtkActor>::New();
		actor->SetMapper(mapper);

		vtkSmartPointer<vtkRenderer> renderer =
			vtkSmartPointer<vtkRenderer>::New();
		vtkSmartPointer<vtkRenderWindow> renderWindow =
			vtkSmartPointer<vtkRenderWindow>::New();
		renderWindow->SetSize(1080,720);
		renderWindow->AddRenderer(renderer);
		vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
			vtkSmartPointer<vtkRenderWindowInteractor>::New();
		renderWindowInteractor->SetRenderWindow(renderWindow);

		renderer->AddActor(actor);
		renderer->SetBackground(40/255, 50/255, 34/255); 

		renderWindow->Render();
		renderWindowInteractor->Start();
		

	return EXIT_SUCCESS;

	
}
