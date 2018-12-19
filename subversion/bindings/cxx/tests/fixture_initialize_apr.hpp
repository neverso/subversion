/*
 * ====================================================================
 *    Licensed to the Apache Software Foundation (ASF) under one
 *    or more contributor license agreements.  See the NOTICE file
 *    distributed with this work for additional information
 *    regarding copyright ownership.  The ASF licenses this file
 *    to you under the Apache License, Version 2.0 (the
 *    "License"); you may not use this file except in compliance
 *    with the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing,
 *    software distributed under the License is distributed on an
 *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *    KIND, either express or implied.  See the License for the
 *    specific language governing permissions and limitations
 *    under the License.
 * ====================================================================
 */

#ifndef SVNXX_TEST_FIXTURE_INITIALIZE_APR_HPP
#define SVNXX_TEST_FIXTURE_INITIALIZE_APR_HPP

#include <iostream>
#include <stdexcept>

#include <apr_general.h>

struct initialize_apr_library
{
  initialize_apr_library()
    {
      const auto status = apr_initialize();
      if (status)
        {
          char errbuf[512];
          std::cerr << "APR initialization failed: "
                    << apr_strerror(status, errbuf, sizeof(errbuf) - 1)
                    << std::endl;
          throw std::runtime_error("APR initialization failed");
        }
    }
  ~initialize_apr_library()
    {
      apr_terminate();
    }
};

BOOST_GLOBAL_FIXTURE(initialize_apr_library);

#endif  // SVNXX_TEST_FIXTURE_INITIALIZE_APR_HPP
