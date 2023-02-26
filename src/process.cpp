#include "process.h"



namespace fs = std::filesystem;
using namespace seqan3;

char order[]="ACGT";
int k=7;


void process(std::string type)
{


    fs::path p = fs::current_path();
    std::string filein = type + ".fasta";

    if(!std::filesystem::exists(p.parent_path()/"SARS_COV_2_Variants"/filein))
    {
        std::cout << "Could not find " << filein << "/n";
        return;
    }
    
    std::cout<<"Processing the file " << filein << "...hold on" << "\n";

    seqan3::sequence_file_input fin{p.parent_path() / "SARS_Cov_2_Variants" / filein};
    int count = 1;
    for (auto & record : fin)
    {   
        /**
        * This function comes directly (with few modifications) from the SeqAn3 Cookbook.
        * This function uses the C++20 std::views::"transform" to recast every character in the vector representing the sequence
        * as it had the alphabet for the type dna4 (only A, C, G, T). Any U is silently casted as T. Any N is casted as A.  
        **/
        auto view2 = record.sequence() | std::views::transform(
                [](auto && in)
                {
                    return static_cast<seqan3::dna4>(std::forward<decltype(in)>(in));
                });

            std::string fileout = "Omicron_" + std::to_string(count) + ".fasta";
            sequence_file_output fout{p.parent_path() / "SARS_Cov_2_Variants" / type / fileout};
            fout.emplace_back(view2, record.id());
            count++;
    }

}   

void process_cgr(std::string type, std::vector<int**> *cgr_vector)
{
    
    fs::path p = fs::current_path();

    for (auto const& dir_entry : fs::directory_iterator{p.parent_path()/"SARS_COV_2_Variants"/type}) 
    {
        /**for every entry in this directory
        * read each sequence using seqan3
        * for every letter in the sequence (a dna5 vector), 
        * turn it into it's char representation
        * push back every new char into the string seq
        * then perform the cgr function on said string
        * and store it in the appropiate vector for dimensionality reduction
        **/

        std::string seq ="";

        sequence_file_input fin{dir_entry.path()};
    
        for (auto & record : fin)
        {   
            //cout << record.sequence().size() << "\n";

            for(auto & letter : record.sequence())
            {
                seq.push_back(letter.to_char());
            }
        }

        cgr_vector->emplace_back(cgr(seq, order, k));
        
        
        //cout << seq << "\n";
        //break;
        //std::cout << dir_entry.path() << '\n';

    }
}

