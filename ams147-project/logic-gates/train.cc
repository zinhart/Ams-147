#include "net/net.hh"
#include "net/training_data.hh"
#include <fstream>
#include <string>
#include <sstream>
#include <random>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <math.h>
void show_vector_vals(std::string label, std::vector<double> &v);
void show_vector_vals(std::string label, std::vector<double> &v, std::fstream &output_file);
int main()
{
	std::string data_dir = "training-data/";
    std::string training_or = data_dir + "out_or.txt";
	std::cout<<training_or<<"\n";
    std::string training_or_results = data_dir +"resultsOrTraining.txt";
    std::string testing_or_results = data_dir + "resultsOrTesting.txt";

    std::string training_xor = data_dir + "out_xor.txt";
    std::string training_xor_results = data_dir + "resultsXOrTraining.txt";

    std::string training_and = data_dir + "out_and.txt";
    std::string training_and_results ="resultsAndTraining.txt";

    std::string training_not = data_dir + "out_no.txt";
    std::string training_not_results = data_dir + "resultsNotTraining.txt";
    training_data train_data(training_or);

    // e.g., { 3, 2, 1 }
    std::vector<unsigned int> topology;
    train_data.get_topology(topology);
    std::cout<<"Topology ";
    for(unsigned i=0; i<topology.size();++i)
    {
       std::cout<<topology[i]<<" ";
    }
    std::cout<<"\n";
    net my_net(topology, training_or, training_or_results);

    std::vector<double> input_vals;
    std::vector<double> target_vals;
    std::vector<double> result_vals;
    int training_pass = 0;
    std::fstream result_file(training_or_results, std::ios::out);
    while (!train_data.isEof())
    {
        ++training_pass;
        //std::cout << std::endl << "Pass " << training_pass;
        result_file<< std::endl << "Pass " << training_pass;

        // Get new input data and feed it forward:
        if (train_data.get_next_inputs(input_vals) != topology[0])
        {
            break;
        }
        show_vector_vals(": Inputs:", input_vals,result_file);
        my_net.forward_propagate(input_vals);

        // Collect the net's actual output results:
        my_net.get_results(result_vals);
        show_vector_vals("Outputs:", result_vals,result_file);

        // Train the net what the outputs should have been:
        train_data.get_target_outputs(target_vals);
        show_vector_vals("Targets:", target_vals,result_file);

        assert(target_vals.size() == topology.back());
        my_net.backward_propagate(target_vals);
        //std::cout << "here2" << std::endl;
        // Report how well the training is working, average over recent samples:
        //std::cout << "Net recent average error: "<< my_net.get_recent_average_error() << std::endl;
        result_file << "Net recent average error: "
            << my_net.get_recent_average_error() << std::endl;
    }

    //std::cout << std::endl << "Done" << std::endl;
    result_file<< std::endl << "Done" << std::endl;
    result_file.close();
    const int True=1.0;
    const int False=0.0;
    unsigned test_cases=500;
    int result;
    int correct_predictions=0;
    std::random_device r;
    std::mt19937 mt(r());
    std::uniform_int_distribution<int>dist(1,4);
    result_file.open(testing_or_results,std::ios::out);
    //test set for or
    for(unsigned int i=0; i<test_cases;++i)
    {
        result= dist(mt);
        if(result==1)
        {
            input_vals.push_back(True);
            input_vals.push_back(True);

        }
        else if(result==2)
        {
            input_vals.push_back(True);
            input_vals.push_back(False);
        }
        else if(result==3)
        {
            input_vals.push_back(False);
            input_vals.push_back(True);

        }
        else if(result==4)
        {
            input_vals.push_back(False);
            input_vals.push_back(False);
        }
        my_net.forward_propagate(input_vals);
        my_net.get_results(result_vals);
        //std::cout<<"\ninput "<<input_vals[0]<<" "<<input_vals[1]<<" result "<<result<<" result val "<<result_vals[0];
        show_vector_vals("Input: ",input_vals,result_file);
        show_vector_vals("Output: ",result_vals,result_file);
        switch (result) {
        case 1:
            (std::round(result_vals[0])==True) ? (++correct_predictions,result_file<<"Pass\n\n") : result_file<<"Fail\n\n";
            break;
        case 2:
            (std::round(result_vals[0])==True) ? ++correct_predictions,result_file<<"Pass\n\n" : result_file<<"Fail\n\n";
            break;
        case 3:
            (std::round(result_vals[0])== True) ? ++correct_predictions , result_file<<"Pass\n\n" : result_file<<"Fail\n\n";
            break;
        case 4:
            (std::round(result_vals[0])==False) ? ++correct_predictions,result_file<<"Pass\n\n" : result_file<<"Fail\n\n";
            break;
        default:
            std::cout<<"wtf\n";
            break;
        }
        input_vals.clear();
    }
    std::cout<<"\nTotal Test cases "<<test_cases;
    std::cout<<"\nTotal correct predictions "<<correct_predictions<<"\n";
    //make input var to test

  /*const std::string end = "`";
    std::string args="\0";
    while(args != end)
    {
        input_vals.clear();
        std::cout<<"Enter arg1\n";
        std::cin>>args;
        input_vals.push_back(std::stod(args));
        std::cout<<"Enter arg2\n";
        args.clear();
        std::cin>>args;
        input_vals.push_back(std::stod(args));
        std::cout<<"size: "<<input_vals.size()<<"\n";
        my_net.feedForward(input_vals);
        my_net.getResults(result_vals);
        show_vector_vals("Input: ",input_vals);
        show_vector_vals("Output: ",result_vals);
        args.clear();
    }*/
	
    return 0;
}
void show_vector_vals(std::string label, std::vector<double> &v)
{
    std::cout << label << " ";
    for (unsigned int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
void show_vector_vals(std::string label, std::vector<double> &v, std::fstream &output_file)
{
    //std::cout << label << " ";
    output_file << label << " ";
    for (unsigned int i = 0; i < v.size(); ++i) {
        //std::cout << v[i] << " ";
        output_file << std::setprecision(10)<< v[i]<<" " ;
    }

    //std::cout << std::endl;
    output_file << std::endl;
}
