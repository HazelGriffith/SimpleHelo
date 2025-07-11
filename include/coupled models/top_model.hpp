#ifndef __TOP_MODEL_HPP__
#define __TOP_MODEL_HPP__

#include "cadmium/modeling/devs/coupled.hpp"
#include "cadmium/lib/iestream.hpp"
#include <iostream>
#include <string>
#include <cassert>

#include "../atomic models/helo.hpp"
#include "../CompsInfo.hpp"

using namespace std;

namespace cadmium::SimpleHelo {
    class Top_model : public Coupled {
        public:
        Top_model(const string& id, bool randFaults): Coupled(id){

            // Declare and initialize all models
			shared_ptr<Helo> helo = addComponent<Helo>("Helo", randFaults);

            // Connect the models with coupling
			string filepath1 = "include/input_data/a.txt";
            auto heloInput = addComponent<cadmium::lib::IEStream<CompsInfo>>("HeloInput",filepath1.c_str());

            addCoupling(heloInput->out, helo->in);
        }
    };
} // namespace cadmium::SimpleHelo

#endif // __TOP_MODEL_HPP__